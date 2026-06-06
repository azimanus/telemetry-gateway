#include <stdio.h>
#include "cpu.h"
#include "memory.h"
#include "uptime.h"
#include "telemetry.h"


int collect_telemetry(telemetry_data_t *telemetry_data)
{

    float cpu_usage = get_cpu_usage();
    float memory_usage = get_memory_usage();
    double uptime_seconds = get_uptime_seconds();

    if(cpu_usage < 0 || memory_usage < 0 || uptime_seconds < 0)
    {
        return -1;
    }
    else
    {
        telemetry_data->cpu_usage = cpu_usage;
        telemetry_data->memory_usage = memory_usage;
        telemetry_data->uptime_seconds = uptime_seconds;
    }

    return 0;

}


void telemetry_print_report(telemetry_data_t *telemetry_data)
{
    

    printf("\nTelemetry Report\n"
                "----------------\n"
                "CPU Usage      : %.2f%%\n"
                "Memory Usage   : %.2f%%\n"
                "Uptime         : %dh %dm\n",
                telemetry_data->cpu_usage,
                telemetry_data->memory_usage,
                ((int)telemetry_data->uptime_seconds/3600),
                ((int)telemetry_data->uptime_seconds % 3600) / 60);
    

}



