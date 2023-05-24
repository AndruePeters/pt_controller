#!/usr/bin/env python3

import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish

for i in range(0, 1000000):
    publish.single("test_topic", payload=f'{i}')