#include <stdio.h>
#include "uptime.h"

double get_uptime_seconds(void) 
{
    FILE *fp = fopen("/proc/uptime", "r");
    double uptime = 0.0;
    if(fp == NULL){
        perror("Failed to open the file /proc/uptime");
            return -1.0;
    }

    fscanf(fp, "%lf", &uptime);
    fclose(fp);
    return uptime;
}


void print_uptime(void) 
{
    double uptime;
    uptime = get_uptime_seconds();
    if (uptime < 0)
    {
        printf("uptime: unavailable\n");
        return;    
    }

    int hours = (int)uptime / 3600;
    int minutes = ((int)uptime % 3600) / 60;
    
    printf("uptime: %dh %dm\n", hours, minutes);
}
