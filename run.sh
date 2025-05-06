#!/bin/bash
mkdir -p log
nohup ./build/bin/MulticastReceive config/B3.json > log/multicast_receive.log 2>&1 &
echo "Started MulticastReceive. Log: log/multicast_receive.log"
