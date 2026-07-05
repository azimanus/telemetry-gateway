#ifndef CONFIG_H
#define CONFIG_H


typedef struct 
{
    int interval_sec;
    char device_id[64];
    char mqtt_host[64];
    int mqtt_port;
    char mqtt_topic[64];
} config_t;


int read_config(config_t *config);

#endif