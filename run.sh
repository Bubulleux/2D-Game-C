#!/bin/bash

SRC="src/"
INCLUDE="./ -I/usr/include -O3 -I/usr/include/mlx -L/usr/include/mlx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd"

SRC_FILE="${SRC}*.c"
FILES=""
for f in $SRC_FILE
do
	FILES="$FILES $f"
done
rm main

CMD="gcc  -o main $FILES -g -I $INCLUDE"
echo $CMD
$CMD