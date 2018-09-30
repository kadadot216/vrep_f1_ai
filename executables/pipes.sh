#!/bin/bash

AIPROG="./ai"
BUFF_NAME="./n4s_buffer"
N4S_NAME="./n4s"
VALGRIND=""
FIFONAME=".fifo_n4s"
trap "rm -f $FIFONAME" EXIT

if [ ! -p $FIFONAME ]; then
  mkfifo $FIFONAME
fi
if ! [ -z "${1+x}"  ]; then
	VALGRIND="valgrind --leak-check=yes --show-reachable=yes"
fi

if [ ! -x $AIPROG ] || [ ! -x $BUFF_NAME ] || [ ! -x $N4S_NAME ]; then
  echo "One of the following is missing or is missing execution user rights"
  echo $AIPROG $BUFF_NAME $N4S_NAME
  exit 1
fi

$VALGRIND "./$AIPROG" < $FIFONAME |  "./$BUFF_NAME" | "./$N4S_NAME" $@ 2> /dev/null |  "./$BUFF_NAME" > $FIFONAME
