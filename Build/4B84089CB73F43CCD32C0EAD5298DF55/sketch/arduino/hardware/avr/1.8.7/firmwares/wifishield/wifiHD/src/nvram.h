#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/arduino/hardware/avr/1.8.7/firmwares/wifishield/wifiHD/src/nvram.h"
#ifndef NVRAM_H
#define NVRAM_H

#include <stdint.h>

int nvram_init(void);
int nvram_read(uint32_t addr, void *data, uint32_t len);
int nvram_write(uint32_t addr, const void *data, uint32_t len);

#endif
