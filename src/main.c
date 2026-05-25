#include <stdio.h>
#include "uptime.h"
#include "memory.h"
#include "cpu.h"

int main(void)
{
    printf("Embedded Linux Telemetry Gateway \n");
    printf("Version: 0.1\n");

    print_uptime();
    print_memory_usage();
    print_cpu_usage();
    

    return 0;
}