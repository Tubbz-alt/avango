#!/bin/bash

# get directory of script
DIR="$( cd "$( dirname "$0" )" && pwd )"

# assuming a local guacmole version is located properly
LOCAL_GUACAMOLE="$DIR/../../../../guacamole"
LOCAL_AVANGO="$DIR/../../../../avango"

# if not, this path will be used
GUACAMOLE=/opt/guacamole/master
AVANGO=/opt/avango/master

# third party libs
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/boost/current/lib:/opt/openscenegraph/3.0.1/lib64/:/opt/zmq/current/lib

# schism
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/schism/current/lib/linux_x86

# avango
export LD_LIBRARY_PATH="$LOCAL_AVANGO/lib":$AVANGO/lib:$LD_LIBRARY_PATH
export PYTHONPATH="$LOCAL_AVANGO/lib/python3.2":"$LOCAL_AVANGO/examples":$AVANGO/lib/python3.2:$AVANGO/examples:$PYTHONPATH

# guacamole
export LD_LIBRARY_PATH="$LOCAL_GUACAMOLE/lib":$GUACAMOLE/lib:$LD_LIBRARY_PATH

# run daemon
if [ -f "$LOCAL_AVANGO/examples/examples_common/daemon.py" ]
then
    "$LOCAL_AVANGO/examples/examples_common/daemon.py" > /dev/null &
else
    "$AVANGO/examples/examples_common/daemon.py" > /dev/null &
fi

filename="/mnt/pitoti/KDN_LOD/PITOTI_KDN_LOD/Spacemonkey_new.kdn"
if [ $# -eq 1 ]; then
  filename=$1
fi

# run program
cd "$DIR" && ./main.py $filename

# kill daemon
kill %1
