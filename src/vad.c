#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "pav_analysis.h"
#include "vad.h"

const float FRAME_TIME = 12.0F; /* in ms. */

/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */
const char *state_str[] = {
  "UNDEF", "S", "V", "INIT", "M_S", "M_V"
};

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float p;
  float am;
} Features;

Features compute_features(const float *x, int N) {
  Features feat;
  feat.zcr = compute_zcr(x,N, 16000);
  feat.p = compute_power(x,N);
  //feat.am = compute_am(x,N);
  return feat;
}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate, float alpha1, float alpha2, float min_silence, float min_voice, float zcr_stv, float zcr_vts) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->first_silence = 1;
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
  vad_data->last_feature = 0;
  vad_data->alpha1 = alpha1;
  vad_data->alpha2 = alpha2;
  vad_data->min_silence = min_silence;
  vad_data->min_voice = min_voice;
  vad_data->maybe_s_counter = 0;
  vad_data->maybe_v_counter = 0;
  vad_data->zcr_stv = zcr_stv;
  vad_data->zcr_vts = zcr_vts;
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
  /* 
   * TODO: decide what to do with the last undecided frames
   */
  VAD_STATE state = vad_data->state;
  if(state == ST_MAYBE_SILENCE) state = ST_VOICE;
  if(state == ST_MAYBE_VOICE) state = ST_SILENCE;
  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  Features f = compute_features(x, vad_data->frame_length);
  vad_data->last_feature = f.p; /* save feature, in case you want to show */

  vad_data->k1 = vad_data->k0 + vad_data->alpha1; 
  vad_data->k2 = vad_data->k1 + vad_data->alpha2;

  switch (vad_data->state) {
  case ST_INIT:
    vad_data->k0 = f.p;
    vad_data->k1 = vad_data->k0 + vad_data->alpha1; 
    vad_data->k2 = vad_data->k1 + vad_data->alpha2;
    vad_data->state = ST_SILENCE;
    break;

  case ST_SILENCE:
    if (f.p > vad_data->k2 || f.zcr > vad_data->zcr_stv){
      vad_data->first_silence=0;
      vad_data->state = ST_MAYBE_VOICE;
      vad_data->maybe_v_counter++;
    }
    break;

  case ST_VOICE:
    if (f.p < vad_data->k1 && f.zcr < vad_data->zcr_vts){
      vad_data->state = ST_MAYBE_SILENCE;
      vad_data->maybe_s_counter++;
    }
    break;

  case ST_MAYBE_VOICE:
    if (f.p > vad_data->k2 || f.zcr > vad_data->zcr_stv){
      if(vad_data->maybe_v_counter*vad_data->frame_length/vad_data->sampling_rate < vad_data->min_voice)
        vad_data->maybe_v_counter++;
      else {
        vad_data->maybe_v_counter = 0;
        vad_data->state = ST_VOICE;
      }
    } else if (f.p < vad_data->k1){
      vad_data->maybe_v_counter = 0;
      vad_data->state = ST_SILENCE;
    }
    break;

  case ST_MAYBE_SILENCE:
    if (f.p < vad_data->k1 && f.zcr < vad_data->zcr_vts){
      if(vad_data->maybe_s_counter*vad_data->frame_length/vad_data->sampling_rate < vad_data->min_silence)
        vad_data->maybe_s_counter++;
      else {
        vad_data->state = ST_SILENCE;
        vad_data->maybe_s_counter = 0;
      }
    } else if (f.p > vad_data->k2){
      vad_data->maybe_s_counter = 0;
      vad_data->state = ST_VOICE;
    }
    break;
  
  case ST_UNDEF:
    break;
  }

  if (vad_data->state == ST_SILENCE ||
      vad_data->state == ST_VOICE)
    return vad_data->state;
  else
    return ST_UNDEF;
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%s\t%f\n", state2str(vad_data->state), vad_data->last_feature);
}
