#include <stdio.h>
#include <string.h>
#include "memory.h"


float get_memory_usage(void)
{

    FILE *fp = fopen("/proc/meminfo", "r");

    double MemTotal = 0.0;
    double MemAvailable = 0.0;
    double UsedMem = 0.0; // calculaed used memory
    float usedPercentage = 0.0; // calculated percentage of the used memory

    char line[100];
    
    if(fp == NULL)
    {
        perror("ERROR: Unavailable file");
        return -1.0;
    }


    while(fgets(line, sizeof(line), fp) != NULL)
    {

        if( strncmp(line, "MemTotal", 8) == 0 )
        {
            sscanf(line, "MemTotal: %lf", &MemTotal);
            //printf("MemTotal:%lf\n", MemTotal);
        }

        if(strncmp(line, "MemAvailable", 12) == 0)
        {
            sscanf(line, "MemAvailable: %lf", &MemAvailable);
            //printf("MemAvailable:%lf\n", MemAvailable);
        }
       
    }
        

    fclose(fp);

    if (MemTotal <= 0 || MemAvailable <= 0)
    {
        return -1.0;
    }


    UsedMem = MemTotal - MemAvailable;
    usedPercentage = (UsedMem / MemTotal) * 100;

    return usedPercentage;

}


void print_memory_usage(void)
{
    float usedMemPercentage;
    usedMemPercentage = get_memory_usage();
    if (usedMemPercentage < 0)
    {
        printf("Memory data: unavailable\n");
        return;    
    }

    
    printf("Memory usage: %.2f%%\n", usedMemPercentage);
}