#include <stdio.h>
#include <unistd.h>
#include "telemetry.h"

int main(void)
{
    telemetry_data_t telemetry_data;
    
    
    printf("Embedded Linux Telemetry Gateway \n");
    printf("Version: 0.2\n");

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

        sleep(5);
    }


    return 0;
}