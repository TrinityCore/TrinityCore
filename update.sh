#! /bin/bash

clear
echo
echo "######################################"
echo "# Welcome to the SingleCore compiler #"
echo "######################################"
echo
read -n1 -r -p "Press any key to continue..." key

git reset --hard
git pull
rm -r -f ./build
mkdir build
cd build
cmake .. -DCONF_DIR=/home/conan/Settings -DTOOLS=0 -DWITH_WARNINGS=0
make -j4
sudo make install
cd ..
