#ifndef MOTOR_H
#define MOTOR_H

#include "pico/types.h"

typedef struct {
    int step;
    int delay_time;
    uint pin_a;
    uint pin_b;
    uint pin_c;
    uint pin_d;
} motor_t;

void motor_init(motor_t* motor);
void motor_rotate_cw(motor_t* motor, int steps);
void motor_rotate_ccw(motor_t* motor, int steps);

#endif
