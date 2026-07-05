#ifndef MQTT_PUBLISHER_H
#define MQTT_PUBLISHER_H

#include "config.h"

int mqtt_publish_payload(const config_t *config, const char *json_payload);

#endif