#include <stdio.h>
#include <mosquitto.h>
#include <string.h>
#include "mqtt_publisher.h"


int mqtt_publish_payload(const config_t *config, const char *json_payload)
{
    struct mosquitto *obj;
    int rc;


    if(config == NULL || json_payload == NULL){
        return -1;
    }

    obj = mosquitto_new(config->device_id, true, NULL);

    if(obj == NULL)
    {
        fprintf(stderr, "Failed to create MQTT client \n");
        return -1;
    }

    rc = mosquitto_connect(obj, config->mqtt_host, config->mqtt_port, 180);
    if(rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "%s\n", mosquitto_strerror(rc));
        mosquitto_destroy(obj);
        return -1;
    }

    rc = mosquitto_publish(obj, NULL, config->mqtt_topic , (int)strlen(json_payload), json_payload, 0, false);
    if(rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "%s\n", mosquitto_strerror(rc));
        mosquitto_disconnect(obj);
        mosquitto_destroy(obj);
        return -1;
    }
    
    mosquitto_disconnect(obj);

    mosquitto_destroy(obj);

    
    return 0;
}