#ifndef TELEMETRY_H
#define TELEMETRY_H

typedef struct 
{
    float cpu_usage;
    float memory_usage;
    double uptime_seconds;
} telemetry_data_t;

int collect_telemetry(telemetry_data_t *telemetry_data);
void telemetry_print_report(telemetry_data_t *telemetry_data);


#endif