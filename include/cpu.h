
#ifndef CPU_H
#define CPU_H

typedef struct 
{
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
}cpu_stat_t;

float get_cpu_usage(void);
void print_cpu_usage(void);

#endif
