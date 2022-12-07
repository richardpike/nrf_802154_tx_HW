/* echo-client.c - Networking echo client */

/*
 * Copyright (c) 2017 Intel Corporation.
 * Copyright (c) 2018 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * The echo-client application is acting as a client that is run in Zephyr OS,
 * and echo-server is run in the host acting as a server. The client will send
 * either unicast or multicast packets to the server which will reply the packet
 * back to the originator.
 *
 * In this sample application we create four threads that start to send data.
 * This might not be what you want to do in your app so caveat emptor.
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(net_echo_client_sample, LOG_LEVEL_DBG);

#include <zephyr/zephyr.h>

#include "nrf_802154.h"

void main(void)
{
    nrf_802154_channel_set(20);

	k_timeout_t time;
	time.ticks = 10000;

	k_sleep(time);

	uint8_t hello_world[] = " Hello World";
	hello_world[0] = 13;

	while(1)
	{
		nrf_802154_transmit_raw(hello_world, NULL);
		k_sleep(time);
	}

}
