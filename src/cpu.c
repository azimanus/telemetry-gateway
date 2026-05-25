#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "cpu.h"

static int read_cpu_stats(cpu_stat_t *s);


float get_cpu_usage(void)
{
    cpu_stat_t previous_stat;
    cpu_stat_t current_stat;


    if(read_cpu_stats(&previous_stat) != 0)
    {
        return -1.0;
    }

    sleep(1);

    if(read_cpu_stats(&current_stat) != 0)
    {
        return -1.0;
    }

    unsigned long previous_total = 
        previous_stat.user +
        previous_stat.nice +
        previous_stat.system +
        previous_stat.idle;

    unsigned long current_total =
        current_stat.user +
        current_stat.nice +
        current_stat.system +
        current_stat.idle;

    unsigned long total_delta = current_total - previous_total;

    unsigned long idle_delta = current_stat.idle - previous_stat.idle;

    if (total_delta == 0)
    {
        return -1.0;
    }

    return((float)(total_delta - idle_delta) / total_delta) * 100.0;

}

void print_cpu_usage(void)
{

    float cpu_usage = get_cpu_usage();

    if(cpu_usage < 0)
    {
        printf("CPU usage: unavailable\n");
        return;
    }

    printf("cpu_usage = %.2f%%\n", cpu_usage);

}


static int read_cpu_stats(cpu_stat_t *s)
{
    char line[100];

    FILE *fp = fopen("/proc/stat", "r");

    if(fp == NULL)
    {
        perror("Error: Unavailable file");
        return -1;
    }

    if(fgets(line, sizeof(line), fp) == NULL)
    {
        fclose(fp);
        return -1;
    }

    fclose (fp);

    int matched = sscanf(line, "cpu %lu %lu %lu %lu", 
            &s->user, 
            &s->nice, 
            &s->system, 
            &s->idle);

    if(matched != 4)
    {
        return -1;
    }
    
    return 0;
}