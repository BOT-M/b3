#!/bin/bash
mkdir -p log
nohup ./build/bin/MulticastReceive config/1_InstrumentDefinition.json > log/1_InstrumentDefinition.log 2>&1 &
nohup ./build/bin/MulticastReceive config/2_SnapshotsRecovery.json > log/2_SnapshotsRecovery.log 2>&1 &
nohup ./build/bin/MulticastReceive config/3_Incremental.json > log/3_Incremental.log 2>&1 &
nohup ./build/bin/MulticastReceive config/4_IncrementalBak.json > log/4_IncrementalBak.log 2>&1 &
nohup ./build/bin/MulticastReceive config/5_Channel_80.json > log/5_all.log 2>&1 &
echo "Started MulticastReceive. Log: log/multicast_receive.log"
