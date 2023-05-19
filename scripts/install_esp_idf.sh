#!/bin/bash

# Install system dependencies
sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0


# Install SDK
mkdir -p ~/sdk/esp
cd ~/sdk/esp
git clone --recursive https://github.com/espressif/esp-idf.git

cd ~/sdk/esp/esp-idf
./install.sh esp32s3,esp32c3


