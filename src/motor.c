#include "hardware/gpio.h"
#include "pico/stdlib.h"

#include "motor.h"

void motor_init(motor_t* motor) {
    motor->step = 0;
    gpio_init(motor->pin_a);
    gpio_init(motor->pin_b);
    gpio_init(motor->pin_c);
    gpio_init(motor->pin_d);
    gpio_set_dir(motor->pin_a, GPIO_OUT);
    gpio_set_dir(motor->pin_b, GPIO_OUT);
    gpio_set_dir(motor->pin_c, GPIO_OUT);
    gpio_set_dir(motor->pin_d, GPIO_OUT);
    gpio_put(motor->pin_a, 1);
}

void motor_rotate_cw(motor_t* motor, int steps) {
    for (int i = 0; i < steps; i++) {
        switch (motor->step) {
            case 0:
                gpio_put(motor->pin_b, 1);
                motor->step = 1;
                break;
            case 1:
                gpio_put(motor->pin_a, 0);
                motor->step = 2;
                break;
            case 2:
                gpio_put(motor->pin_c, 1);
                motor->step = 3;
                break;
            case 3:
                gpio_put(motor->pin_b, 0);
                motor->step = 4;
                break;
            case 4:
                gpio_put(motor->pin_d, 1);
                motor->step = 5;
                break;
            case 5:
                gpio_put(motor->pin_c, 0);
                motor->step = 6;
                break;
            case 6:
                gpio_put(motor->pin_a, 1);
                motor->step = 7;
                break;
            case 7:
                gpio_put(motor->pin_d, 0);
                motor->step = 0;
                break;
        }
        sleep_us(motor->delay_time);
    }
}

void motor_rotate_ccw(motor_t* motor, int steps) {
    for (int i = 0; i < steps; i++) {
        switch (motor->step) {
            case 0:
                gpio_put(motor->pin_d, 1);
                motor->step = 7;
                break;
            case 1:
                gpio_put(motor->pin_b, 0);
                motor->step = 0;
                break;
            case 2:
                gpio_put(motor->pin_a, 1);
                motor->step = 1;
                break;
            case 3:
                gpio_put(motor->pin_c, 0);
                motor->step = 2;
                break;
            case 4:
                gpio_put(motor->pin_b, 1);
                motor->step = 3;
                break;
            case 5:
                gpio_put(motor->pin_d, 0);
                motor->step = 4;
                break;
            case 6:
                gpio_put(motor->pin_c, 1);
                motor->step = 5;
                break;
            case 7:
                gpio_put(motor->pin_a, 0);
                motor->step = 6;
                break;
        }
        sleep_us(motor->delay_time);
    }
}
