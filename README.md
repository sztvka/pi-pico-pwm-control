# pi-pico-pwm-control
Library for setting Raspberry Pi Pico's PWM as Hz with dutycycle or miliseconds.



## Usage

1. Clone the repo, enable PWM peripheral and attach files in CMakeLists.txt
```cmake
add_executable(myproject
        main.c
        pwm_control.c pwm_control.h)


target_link_libraries(myproject hardware_pwm)
```
2. Use the library in your code
```c
#include "pwm_control.h"
pwm_control_init(20); //init on gpio 20
pwm_control_init(19); //init on gpio 19
pwm_control_set(1000, 0.25f, 20); // output 1kHz 25% dutycycle on gpio 20
pwm_control_set_ms(20, 1.5f, 19); //PWM with 20ms period and 1.5ms ontime on gpio 19
```

### Syntax
```c
//Initialize PWM peripheral on pin
pwm_control_init(uint pin);

// Set PWM frequency and duty cycle, 
// returns 0 on success, 1 on failure
pwm_control_set(uint freq, float duty, uint pin);

// period in milliseconds, ontime in milliseconds, gpio pin, 
// returns 0 on success, 1 on failure
pwm_control_set_ms(uint period, float ontime, uint pin);

// disable output
pwm_control_disable(uint pin);
```

## Hardware considerations
This library is calibrated with an assumption that the peripheral clock speed is left default. Running this lib with a different peripheral clock speed will cause shifts in the output freqeuncy.

PWM output is **capped between 19Hz and 1MHz** due to hardware limitations. Achieving higher output frequency is possible, but the square wave gets distorted way too much to my liking. Lower output frequencies should be realized with a different approach.
