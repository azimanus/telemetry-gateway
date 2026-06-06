#ifndef CONFIG_H
#define CONFIG_H


typedef struct 
{
    int interval_sec;
    char device_id[64];
} config_t;


int read_config(config_t *config);

#endif