#!/bin/bash

year=$1
day=$2

cd year

mkdir $day
cd $day
touch ${day}_solution.cpp
touch ${day}_example.txt
touch ${day}_input.txt

