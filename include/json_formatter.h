#ifndef JSON_FORMATTER_H
#define JSON_FORMATTER_H

#include<stddef.h>
#include "telemetry.h"
#include "config.h"




int format_telemetry_json(const telemetry_data_t *telemetry_data, const config_t *config, char *buffer, size_t buffer_size);

#endif