/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 300
DigitalOut led1(LED1);
DigitalIn bottone(PC_13);

int main() {
  printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

  while (true) // esegue il lampeggio leggendo il valore del led e commutandolo
  {
    // led1 = !led1;  così commuto, nell'altro modo impongo due tempi diversi commutando manualmente
    if (bottone == 0) {
      led1.write(1);
      thread_sleep_for(100); // equivalente di hal_delay bloccante in cui il microcontrollore non può fare nulla
      led1.write(0);
      thread_sleep_for(50);
    }
  }
}
