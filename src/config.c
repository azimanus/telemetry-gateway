#include <stdio.h>
#include <string.h>
#include "config.h"


int read_config(config_t *config)
{
    char line[64];
    
    FILE *fp = fopen("config/telemetry.conf", "r");
    if(fp == NULL)
    {
        perror("Error: Unavailable file");
        return -1;
    }


    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "interval_sec=", 13) == 0)
        {
            sscanf(line, "interval_sec=%d", &config->interval_sec);
        }
        else if (strncmp(line, "device_id=", 10) == 0) 
        {
            sscanf(line, "device_id=%63s", config->device_id);
        
        }
        else
        {

        }
    }

    fclose(fp);

    return 0;


}