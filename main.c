/*
 * Copyright (c) <YEAR(S)>, Regents of the University of California
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the University of California, Berkeley nor the names
 *   of its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * main.c for project to run on ImageProc board
 *
 * by Andrew Pullin, et al.
 *
 * v.0.1
 *
 * Revisions:
 *  apullin     12/12/2014      Initial version
 *
 * Notes:
 *  - This should compiler, but not set up any peripherals (PWM, SPI, etc) or
 *    or any other functions (radio, memory, etc). Only clocks and ports.
 *    slock module is considered to be a core funciton, and is included here.
 *  - As of v.0.1 , the prebuild step is not included.
 *
 * Usage:
 *  Add in module include and initializations to extend this template.
 */

// XC compiler include
#include <xc.h>

// imageproc-lib includes
#include "utils.h"          // CSP and BSP
#include "init_default.h"   // port and clocks
#include "sclock.h"         // microsecond timer

// module includes
//#include "mpu6000.h"      // MPU6000, gyro + accelerometer

int main() {
    // Processor Initialization
    SetupClock();
    SwitchClocks();
    SetupPorts();

    // Microsecond system timer
    sclockSetup();

    // Add module setup calls here
    // mpuSetup(); // MPU6000 module

    //Example: Turn on a single LED
    LED_1 = 1;
    LED_2 = 0;
    LED_3 = 0;

    //Main loop
    while(1){
        //Example: Toggle an LED at 1Hz
        delay_ms(1000);
        LED_2 = ~LED_2;
    }

    //This point should never be reached
    return 0; 
}
