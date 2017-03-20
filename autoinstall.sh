#!/bin/sh
apt-get update
apt-get upgrade -y
apt-get install curl wget tar ntp sudo -y
echo "1.system updated and requirements installed."
adduser lisk
usermod -aG sudo lisk
echo "2.lisk user added, grant sudo privilege"
echo "3.switch to lisk,and download install script from official site."
runuser -l lisk -c "rm /home/lisk/installLisk.sh"
runuser -l lisk -c "cd /home/lisk  & wget https://downloads.lisk.io/lisk/main/installLisk.sh"
runuser -l lisk -c "cd /home/lisk & bash installLisk.sh install -r main -0 no -d /home/lisk/"
