#include <stdio.h>
#include <unistd.h>
#include "telemetry.h"
#include "config.h"

int main(void)
{
    telemetry_data_t telemetry_data;

    config_t config = {
    .interval_sec = 5,
    .device_id = "linux-gateway-001"
    };
    
    
    printf("Embedded Linux Telemetry Gateway \n");
    printf("Version: 0.2\n");

    if(read_config(&config) < 0)
    {
        printf("Error: unavailable config parameters.\n");

    }

    while(1)
    {
        if(collect_telemetry(&telemetry_data) == 0)
        {
            telemetry_print_report(&telemetry_data);

        }   
        else
        {
            printf("Failed to collect telemetry data\n");
        }

        sleep(config.interval_sec);
    }


    return 0;
}