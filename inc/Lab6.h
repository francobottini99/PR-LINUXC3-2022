
#ifndef __LAB6_H__
#define __LAB6_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

typedef u_int8_t boolean;

typedef struct 
{
    u_int16_t version;
    u_int16_t drxVersion;
    u_int8_t  reserved1[4];
    double    initCW;
    float     azimuth;
    float     elevation;
    u_int16_t idVolumen;
    u_int16_t idBarrido;
    u_int16_t idCnjunto;
    u_int16_t idGrupo;
    u_int16_t idPulso;
    boolean   iniBarrido;
    boolean   finBarrido;
    boolean   finGrupo;
    boolean   inhibido;
    u_int16_t validSamples;
    u_int16_t nroAdquisicion;
    u_int8_t  reserved2[2];
    u_int32_t nroSecuencia;
    u_int64_t readTime_high;
    u_int64_t readTime_low;
    u_int8_t  reserved3[64];
} RMA1;

RMA1** get_samples(char* mapaddr, u_int32_t mapbytes, u_int8_t* n);
char* load_rawdata(char* file, u_int32_t* mapbytes);

#endif /* __LAB6_H__ */