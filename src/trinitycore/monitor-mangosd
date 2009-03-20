#!/bin/bash
# Massive Network Game Object Server
# Monitoring Script

pid=`ps ax | awk '($5 ~ /mangos-worldd/) { print $1 }'`
cpu=`top -b -n 1 -p $pid | awk '($12 ~ /mangos-worldd/) { print $9 }'`
#echo $pid
#echo $cpu
intcpu=${cpu%.*}
#echo $intcpu
if [ "$intcpu" -gt "95" ]
then
	kill -9 $pid
	echo "Killed MaNGOS for exceeding it's cpu limit."
	echo `date` ", Killed MaNGOS for $intcpu% CPU Usage." >> serverlog
else
	echo "MaNGOS Passes the cpu test."
fi
