#!/bin/sh

sudo apt update && sudo apt upgrade
sudo apt install -y mosquitto mosquitto-clients
pip install paho-mqtt