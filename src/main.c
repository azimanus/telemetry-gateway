#include <stdio.h>
#include "telemetry.h"

int main(void)
{
    telemetry_data_t telemetry_data;
    
    
    printf("Embedded Linux Telemetry Gateway \n");
    printf("Version: 0.1\n");

    //print_uptime();
    //print_memory_usage();
    //print_cpu_usage();

    if(collect_telemetry(&telemetry_data) == 0)
    {
        telemetry_print_report(&telemetry_data);

    }
    else
    {
        printf("Failed to collect telemetry data\n");
    }

    
    

    return 0;
}