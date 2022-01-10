#!/bin/bash

year=$1
day=$2

cd $year

mkdir $day
cd $day
touch ${day}_solution.cpp
touch ${day}_example.txt
touch ${day}_input.txt

echo "#include <bits/stdc++.h>" >> ${day}_solution.cpp
echo "" >> ${day}_solution.cpp
echo "using namespace std;" >> ${day}_solution.cpp
echo "" >> ${day}_solution.cpp
echo "void partOne() {}" >> ${day}_solution.cpp
echo "" >> ${day}_solution.cpp
echo "void partTwo() {}" >> ${day}_solution.cpp
echo "" >> ${day}_solution.cpp
echo "int main() {" >> ${day}_solution.cpp
echo "    partOne();" >> ${day}_solution.cpp
echo "    // partTwo();" >> ${day}_solution.cpp
echo "    return 0;" >> ${day}_solution.cpp
echo "}" >> ${day}_solution.cpp


echo $day created under folder $year


