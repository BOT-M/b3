ps -ef | grep MulticastReceive | grep -v grep | awk '{print $2}' | xargs kill -9
