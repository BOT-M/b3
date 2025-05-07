#!/bin/bash
mkdir -p log
nohup ./build/bin/MulticastReceive config/Channel_1.json > log/InstrumentDefinition.log 2>&1 &
nohup ./build/bin/MulticastReceive config/Channel_2.json > log/SnapshotsRecovery.log 2>&1 &
nohup ./build/bin/MulticastReceive config/Channel_3.json > log/Incremental.log 2>&1 &
nohup ./build/bin/MulticastReceive config/Channel_4.json > log/IncrementalBak.log 2>&1 &
nohup ./build/bin/MulticastReceive config/Channel_80.json > log/all.log 2>&1 &
echo "Started MulticastReceive. Log: log/multicast_receive.log"
