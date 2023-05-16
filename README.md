# PT Controller

This is a pan and tilt controller for the BESCOR_MP101 although it likely might support others in the future.

## Components

### Server

Accepts input
Interprets inputs to send commands to clients
Read messages from clients
Synchronize with clients to enable client modes (IR programming)

### Client

Receives commands from server
Controls the motor directly or interfaces with a motor controller
RGB status indicator
LANC interface
Potential WIFI SDK interface for cameras like Sony


## Setup for Development

https://github.com/dorssel/usbipd-win

chmod 666 /dev/ttyUSB0 sudo adduser druep dialout tty sudo service udev restart

sudo udevadm control --reload usbipd wsl attach --busid 

# Uses a MQTT Server
C++ Potential Clients: https://github.com/redboltz/mqtt_cpp

Paho: https://github.com/eclipse/paho.mqtt.cpp

