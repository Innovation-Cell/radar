#!/bin/sh

#              Copyright 2012-2016 by Kvaser AB, Molndal, Sweden
#                         http://www.kvaser.com
#
#  This software is dual licensed under the following two licenses:
#  BSD-new and GPLv2. You may use either one. See the included
#  COPYING file for details.
#
#  License: BSD-new
#  ===============================================================================
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#      * Redistributions of source code must retain the above copyright
#        notice, this list of conditions and the following disclaimer.
#      * Redistributions in binary form must reproduce the above copyright
#        notice, this list of conditions and the following disclaimer in the
#        documentation and/or other materials provided with the distribution.
#      * Neither the name of the <organization> nor the
#        names of its contributors may be used to endorse or promote products
#        derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
#  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#  DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
#  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
#  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
#  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
#  License: GPLv2
#  ===============================================================================
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#
#  ---------------------------------------------------------------------------

MODNAME=usbcanII
DEPMOD=`which depmod`
UDEVCTRL=`which udevcontrol 2>/dev/null`
UDEVADM=`which udevadm`
UDEVD=`which udevd`

/usr/sbin/$MODNAME.sh stop 2>/dev/null
rmmod $MODNAME 2>/dev/null

# Check if module is still loaded
MODLOADED=$(lsmod | grep $MODNAME)
if [ $? -eq 0 ] ; then
  echo "*************************************************************************"
  echo "WARNING: $MODNAME could not be removed! Either unplug USB device and     "
  echo "          remove $MODNAME manually after uninstallation or do a reboot.  "
  echo "*************************************************************************"
fi

rm -f /lib/modules/`uname -r`/kernel/drivers/usb/misc/$MODNAME.ko \
      /usr/sbin/$MODNAME.sh

if [ -z $UDEVD ] ; then
  $UDEVADM control --reload-rules ;
else
  if [ `udevd --version` -lt 128 ] ; then
    $UDEVCTRL reload_rules ;
  else
    $UDEVADM control --reload-rules ;
  fi
fi


echo Remove SocketCAN Kvaser USB driver from blacklist.

if [ -f /etc/modprobe.conf ] ; then
  # CentOS/Redhat/RHEL/Fedora Linux...
  CONF=/etc/modprobe.conf
  BLACKLIST="alias     kvaser_usb   /dev/null"
else
  # Debian/Ubuntu Linux
  CONF=/etc/modprobe.d/kvaser.conf
  BLACKLIST="blacklist kvaser_usb"
  if [ ! -f $CONF ] ; then
    touch $CONF
  fi
fi

grep -v "^${BLACKLIST}" < $CONF                          > newconf

cat newconf > $CONF
rm newconf

$DEPMOD -a
if [ "$?" -ne 0 ] ; then
  echo Failed to execute $DEPMOD -a
fi