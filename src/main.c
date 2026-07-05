#include <mosquitto.h>
#include <stdio.h>
#include <unistd.h>
#include "telemetry.h"
#include "config.h"
#include "json_formatter.h"
#include "logger.h"
#include "mqtt_publisher.h"

int main(void)
{
    telemetry_data_t telemetry_data;

    config_t config ;

    char buffer[256];
    int json_format_status;
    size_t buffer_size;

    buffer_size = sizeof(buffer);

    if(read_config(&config) < 0)
    {
        printf("Error: unavailable config parameters.\n");
        mosquitto_lib_cleanup();
        return -1;
    }

    printf("Embedded Linux Telemetry Gateway \n");
    printf("Device ID   : %s\n", config.device_id);
    printf("Interval    : %d sec\n", config.interval_sec);
    printf("Version     : 0.4\n");

    mosquitto_lib_init();
    
    while(1)
    {
        if(collect_telemetry(&telemetry_data) == 0){
            telemetry_print_report(&telemetry_data);

        }   
        else{
            printf("Failed to collect telemetry data\n");
            sleep(config.interval_sec);
            continue;
        }

        json_format_status = format_telemetry_json(&telemetry_data, &config, buffer, buffer_size);

        if(json_format_status < 0){
             printf("Error: json formatting error\n");
             sleep(config.interval_sec);
             continue;
        }
        else if (json_format_status > 0) {
            printf("Error: Buffer too small\n");
            sleep(config.interval_sec);
            continue;
        
        }
        else{
        
            printf("JSON Payload: %s\n", buffer);
        }

        if(log_telemetry_payload(buffer) < 0){
            printf("Failed to log the telemetry\n");
            sleep(config.interval_sec);
            continue;
        }

        if(mqtt_publish_payload(&config, buffer) < 0){
            printf("Failed to publish the payload via MQTT\n");
        }
        
        sleep(config.interval_sec);   
        
    }
    
    mosquitto_lib_cleanup();

    


    return 0;
}