#include "../inc/Lab6.h"

int main(void)
{
    u_int8_t n;
    u_int32_t mapbytes;

    char* mapaddr = load_rawdata("rawdata/datos", &mapbytes);
    RMA1** samples = get_samples(mapaddr, mapbytes, &n);

    u_int32_t sum = 0;
    for (u_int8_t i = 0; i < n; i++)
        sum += samples[i]->validSamples;

    printf("-> Total of samples: %d\n", n);
    printf("-> Prom of validSamples: %d\n", sum / n);
    
    free(samples);

    munmap(mapaddr, mapbytes);

    return EXIT_SUCCESS;
}

char* load_rawdata(char* file, u_int32_t* mapbytes)
{
    char* mapaddr;
    struct stat stat_result;
    int fd;
    
    if((fd = open(file, O_RDONLY)) < 0)
    {
        fprintf(stderr, "ERROR: Cannot open source file <%s>\n", file);
        exit(EXIT_FAILURE);
    }

    fstat(fd, &stat_result);

    mapaddr = (char*)mmap(NULL, stat_result.st_size, PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

    if(mapaddr == MAP_FAILED)
    {
        fprintf(stderr, "ERROR: Cannot mapping file <%s> in RAM\n", file);
        exit(EXIT_FAILURE);
    }

    *mapbytes = stat_result.st_size;

    return mapaddr;
}

RMA1** get_samples(char* mapaddr, u_int32_t mapbytes, u_int8_t* n)
{
    RMA1** samples = malloc(sizeof(RMA1*) * (sizeof(RMA1*) / mapbytes));
    u_int16_t offset = 0;
    
    *n = 0;

    while(offset < mapbytes)
    {
        samples[*n] = malloc(sizeof(RMA1*));
        samples[(*n)++] = (RMA1*)(mapaddr + offset);
        offset = (*n) * sizeof(RMA1);
    }

    return samples;
}