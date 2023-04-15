#!/bin/bash

DIR_P2=$HOME/PAV/P2
DB=$DIR_P2/db.v4
CMD=$DIR_P2/bin/vad 
BESTSCORE=0

ninja -C bin
apt install dc 
alpha1=7.6 alpha2=3.4 min_silence=0.1 min_voice=0 zcr_stv=3400 zcr_vts=3600

for alpha1 in $(seq 0 1 10); do 
for alpha2 in $(seq 0 1 6); do
#for min_silence in $(seq 0 .010 0.2); do
#for min_voice in $(seq 0 .01 0.2); do
#for zcr_stv in $(seq 0 100 4000); do
#for zcr_vts in $(seq 0 100 4000); do
    echo -e -n "\rVAD with alpha1=$alpha1, alpha2=$alpha2, min_silence=$min_silence, min_voice=$min_voice, zcr_stv=$zcr_stv and zcr_vts=$zcr_vts"
    for filewav in $DB/*/*wav; do
        filevad=${filewav/.wav/.vad}
        $CMD -i $filewav -o $filevad -1 $alpha1 -2 $alpha2 -S $min_silence -V $min_voice -Z $zcr_stv, -X $zcr_vts || exit 1
    done
    A=$(scripts/vad_evaluation_noverb.pl $DB/*/*lab)
    if ! echo "$A $BESTSCORE -p" | dc | grep > /dev/null ^-; then
        BESTSCORE=$A
        BESTP1=$PARAM1
        BESTP2=$PARAM2
        clear
        echo "New Best score $BESTSCORE with parameters alpha1=$alpha1, alpha2=$alpha2, min_silence=$min_silence, min_voice=$min_voice, zcr_stv=$zcr_stv and zcr_vts=$zcr_vts"
    fi
     done  done # done  done # done
exit 0
