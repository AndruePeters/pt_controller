#!/usr/bin/env bash
cd build
python $IDF_PATH/components/esptool_py/esptool/esptool.py -p $1 write_flash @flash_project_args
python $IDF_PATH/tools/idf_monitor.py -p $1
https://github.com/dorssel/usbipd-win
chmod 666 /dev/ttyUSB0
sudo adduser druep dialout tty
sudo service udev restart

 sudo udevadm control --reload