#include <stdio.h>
#include "logger.h"
#include <time.h>


int log_telemetry_payload(const char *json_payload)
{
    char timestamp[32];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    FILE *fp = fopen("logs/telemetry.log", "a");

    if(fp == NULL){
        perror("Error opening log file");
        return -1;
    }

    if(fprintf(fp, "%s %s\n", timestamp, json_payload) < 0){
        fclose(fp);
        return -1;
    }
   
    fclose(fp);

    return 0;

}