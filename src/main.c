#include <stdio.h>
#include <unistd.h>
#include "telemetry.h"
#include "config.h"
#include "json_formatter.h"

int main(void)
{
    telemetry_data_t telemetry_data;

    config_t config = {
    .interval_sec = 5,
    .device_id = "linux-gateway-001"
    };

    char buffer[256];
    size_t buffer_size;

    buffer_size = sizeof(buffer);
    
    
    printf("Embedded Linux Telemetry Gateway \n");
    printf("Device ID   : %s\n", config.device_id);
    printf("Interval    : %d sec\n", config.interval_sec);
    printf("Version     : 0.3\n");

    if(read_config(&config) < 0)
    {
        printf("Error: unavailable config parameters.\n");

    }

    while(1)
    {
        if(collect_telemetry(&telemetry_data) == 0){
            telemetry_print_report(&telemetry_data);

        }   
        else{
            printf("Failed to collect telemetry data\n");
        }

        if(format_telemetry_json(&telemetry_data, &config, buffer, buffer_size) < 0){
             printf("Error: json formatting error");
        }
        else if (format_telemetry_json(&telemetry_data, &config, buffer, buffer_size) > 0) {
            printf("Error: Buffer too small");
        
        }
        else{
        
            printf("JSON Payload: %s\n", buffer);
        }

        sleep(config.interval_sec);
    }


    return 0;
}