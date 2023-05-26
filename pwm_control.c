//
// Created by sztuka on 26.05.2023.
//

#include "pwm_control.h"


void pwm_control_init(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_set_function(pin, GPIO_FUNC_PWM);
}

uint pwm_control_set(uint freq, float duty, uint pin){
    uint slice = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);
    uint wrap;
    uint clkdiv = 1;
    if (freq < 20 || freq > 1000000){
        return 1;
    }
    if(freq < 1900 && freq >= 190){
        freq *=10;
        clkdiv = 10;
    }
    else if(freq < 190 && freq >= 19){
        freq *=100;
        clkdiv = 100;
    }
    else{
        clkdiv = 1;
        freq = freq;
    }
    wrap = (1.9*65535)/(freq/1000);

    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, channel, (uint16_t)(wrap*duty));
    pwm_set_clkdiv(slice, (float)clkdiv);
    pwm_set_enabled(slice, true);
    return 0;
}

uint pwm_control_set_ms(uint period, float ontime, uint pin){
    uint freq = 1000/period;
    float duty = ontime/period;
    uint slice = pwm_gpio_to_slice_num(pin);
    uint channel = pwm_gpio_to_channel(pin);
    uint wrap;
    uint clkdiv = 1;
    if (freq < 20 || freq > 1000000){
        return 1;
    }
    if(freq < 1900 && freq >= 190){
        freq *=10;
        clkdiv = 10;
    }
    else if(freq < 190 && freq >= 19){
        freq *=100;
        clkdiv = 100;
    }
    else{
        clkdiv = 1;
        freq = freq;
    }
    wrap = (1.9*65535)/(freq/1000);

    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, channel, (uint16_t)(wrap*duty));
    pwm_set_clkdiv(slice, (float)clkdiv);
    pwm_set_enabled(slice, true);
    return 0;
}


void pwm_control_disable(uint pin){
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_enabled(slice, false);
}