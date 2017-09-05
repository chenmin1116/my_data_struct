#!/bin/bash

ROOT=$(pwd)
BIN=chat_system
pid=''

proc=$(basename $0)
usage(){
	printf "Usage:\n\t%s [start(-s)|stop(-t)|restart(-rs)|status(-st)]\n\n" "$proc"
}

is_exist(){
	pid=$(pidof $BIN)
	if [ -z "$pid" ];then
		return 1;
	else
		return 0;
	fi
}

start_server(){
	if is_exist; then
		echo "server is running, pid : $pid"
	else
		$ROOT/$BIN 0 9999
		echo "server starting ... done"
	fi
}

stop_server(){
	if is_exist; then
		kill -9 $pid
		echo "server stoping ... done"
	else
		echo "server is not running, please start frist!"
	fi
}

restart_server(){
	stop_server
	start_server
}

status_server(){
	if is_exist; then
		echo "server is ok, pid : $pid"
	else
		echo "server is not ok"
	fi
}

if [ $# -ne 1 ]; then
	usage
	exit 1
fi

case $1 in
	start | -s )
		start_server
	;;
	stop | -t )
		stop_server
	;;
	restart | -rs )
		restart_server
	;;
	status | -st )
		status_server
	;;
	* )
	usage
	exit 2
	;;
esac
