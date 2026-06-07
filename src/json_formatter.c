#include <stdio.h>
#include "telemetry.h"
#include "config.h"
#include "json_formatter.h"

int format_telemetry_json(const telemetry_data_t *telemetry_data, const config_t *config, char *buffer, size_t buffer_size)
{
    int written = snprintf(buffer, buffer_size, "{ "
                            "\"device_id\": \"%s\", "
                            "\"cpu_usage\": %.2f, "
                            "\"memory_usage\": %.2f, "
                            "\"uptime_seconds\": %.0f "
                            "} ", 
                            config->device_id,
                            telemetry_data->cpu_usage,
                            telemetry_data->memory_usage,
                            telemetry_data->uptime_seconds);

    if(written < 0)
    {
        return -1;
    }
    else if((size_t)written >= buffer_size)
    {
        return 1;
    }
   

    return 0;

         
}