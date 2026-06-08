#include <stdio.h>
#include "logger.h"


int log_telemetry_payload(const char *json_payload)
{
    FILE *fp = fopen("logs/telemetry.log", "a");

    if(fp == NULL){
        perror("Error: Unavailable file");
        fclose(fp);
        return -1;
    }

    if(fprintf(fp, "%s\n", json_payload) < 0){
        return -1;
    }
   
    fclose(fp);

    return 0;

}