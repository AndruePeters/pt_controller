# pt_controller
Pan &amp; Tilt Controller for the Bescor 
https://github.com/dorssel/usbipd-win

chmod 666 /dev/ttyUSB0
sudo adduser druep dialout tty
sudo service udev restart

sudo udevadm control --reload
usbipd wsl attach --busid <busid>