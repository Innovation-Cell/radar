Installation-
Re-download the Kvaser Linux SDK (latest version). You will find the downloads on Kvaser's Downloads page.

When you download the file (linuxcan.tar.gz), it will most likely end up in your ~/Downloads folder. After this, execute the following commands:

cd ~/Downloads
sudo mv linuxcan.tar.gz /usr/src
cd /usr/src
sudo rm -rf linuxcan/
sudo tar xvf linuxcan.tar.gz
cd linuxcan/
sudo make
sudo make install

{If you have a Kvaser PCIe card, you will also need to do the following:
gksudo gedit /etc/modules
At the bottom of this file, add pciefd. Save the file and close it.
}
Reboot your machine.

To verify functionality after a reboot, execute the following commands:
cd /usr/src/linuxcan/canlib/examples
./listChannels

This should output a list of devices similar to the following (assuminig you have at least one Kvaser device connected):
Found 1 channel(s).
channel  0 = Kvaser Leaf Light v2,  73-30130-00685-0, 25593, 3.3.0.769

#P.S-If you have issues building kvcommon, try upgrading to linuxcan-5.21.240 or greater.
#rosrun kvaser esr_ros_can_source.py // this will initialise the can communication between the radar and the PC 
#rosrun kvaser esr_visualiser.py // runs the visualiser to visualise data from the CAN in a window
