#!/bin/bash

# get directory of script
DIR="$( cd "$( dirname "$0" )" && pwd )"

# assuming a local guacmole version is located properly
#LOCAL_GUACAMOLE="$DIR/../../../guacamole"
#LOCAL_AVANGO="$DIR/../../../avango"

LOCAL_GUACAMOLE=/home/wabi7015/Programming/guacamole
LOCAL_AVANGO=/home/wabi7015/Programming/avango


# if not, this path will be used
GUACAMOLE=/opt/guacamole/master
AVANGO=/opt/avango/master

# third party libs
export LD_LIBRARY_PATH=/opt/boost/current/lib:/opt/zmq/current/lib

# schism
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/schism/current/lib/linux_x86
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/wabi7015/Programming/schism/lib/linux_x86
# avango
export LD_LIBRARY_PATH="$LOCAL_AVANGO/lib":$AVANGO/lib:$LD_LIBRARY_PATH:/opt/lamure/install/lib:/opt/Awesomium/lib
export PYTHONPATH="$LOCAL_AVANGO/lib/python3.5":"$LOCAL_AVANGO/examples":$AVANGO/lib/python3.5:$AVANGO/examples:/opt/kinect-resources/rgbd-framework/netvalue-py/lib

# guacamole
export LD_LIBRARY_PATH="$LOCAL_GUACAMOLE/lib":$GUACAMOLE/lib:$LD_LIBRARY_PATH

# run daemon
#if [ -f "$LOCAL_AVANGO/examples/examples_common/daemon.py" ]
#then
#    python3 $LOCAL_AVANGO/examples/examples_common/daemon.py &
#else
#    python3 $AVANGO/examples/examples_common/daemon.py > /dev/null &
#fi

# run daemon
echo "BEFORE EXECUTING DEMON"
python3 ./daemon.py > /dev/null &

SCENE_NUMBER=$1

# run program
cd "$DIR" && python3 ./global_scene_server.py $SCENE_NUMBER


# kill daemon
kill %1
kill %2
