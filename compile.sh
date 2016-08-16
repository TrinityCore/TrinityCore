#! /bin/bash

cd build
echo Start the servers build
echo
make -j4
echo
echo Make sure the compile is done 100%
echo
read -n1 -r -p "Press any key to continue..." key

clear
sudo make install
cd ~
