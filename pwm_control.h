//
// Created by sztuka on 26.05.2023.
//
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#ifndef PICO_TEST_PWM_CONTROL_H
#define PICO_TEST_PWM_CONTROL_H

#endif //PICO_TEST_PWM_CONTROL_H
struct pwm_control {
    uint freq;
    uint pin;
    uint duty;
};
void pwm_control_init(uint pin);
uint pwm_control_set(uint freq, float duty, uint pin);
uint pwm_control_set_ms(uint period, float ontime, uint pin);
void pwm_control_disable(uint pin);