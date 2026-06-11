#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/arduino/hardware/avr/1.8.7/firmwares/wifishield/wifiHD/src/SOFTWARE_FRAMEWORK/SERVICES/LWIP/lwip-port-1.3.2/HD/if/include/netif/wlif.h"
#ifndef __NETIF_NRWLANIF_H__
#define __NETIF_NRWLANIF_H__

#include "lwip/netif.h"
#include "lwip/err.h"

err_t wlif_init(struct netif *netif);
void wlif_poll(struct netif *netif);

#endif
