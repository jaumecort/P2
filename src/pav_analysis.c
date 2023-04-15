#include <math.h>
#include "pav_analysis.h"

double PI = 3.14159265358979323846;
//Potencia media de la señal en decibelios

float compute_power(const float *x, unsigned int N) {
    float sum = 1e-12, res;
    for(unsigned int i = 0; i<N; i++) sum += (x[i])*(x[i]);
    res = 10*log10(sum/N);
    return res;
}

float compute_power_hamming(const float *x, unsigned int N) {
    float sum = 1e-12, res, w, vent = 0;
    for(unsigned int i = 0; i<N; i++){
        w = 0.53836-0.46164*(cos(2*PI*i/(N-1)));
        sum += (x[i]*w)*(x[i]*w);
        vent = w*w;
    } 

    res = 10*log10(sum/vent);
    return res;
}

//Amplitud media
float compute_am(const float *x, unsigned int N) {
    float sum = 0;
    for(unsigned int i=0;i<N;i++) sum = sum + fabs(x[i]);
    return sum/N;
}


//Tasa de cruces por cero
float compute_zcr(const float *x, unsigned int N, float fm) {
    float sum=1e-12;
    int mult = fm/(2*(N-1));
    for(unsigned int i = 0; i<N-1; i++)
        if((x[i]>=0 && x[i+1]<0) || (x[i]<0 && x[i+1]>=0))
            sum++;
    return mult*sum;
}
