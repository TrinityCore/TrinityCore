#! /bin/bash

clear
echo
echo "######################################"
echo "# Welcome to the SingleCore compiler #"
echo "######################################"
echo
read -n1 -r -p "Press any key to continue..." key

echo Restoring modified files to default.
git reset --hard
echo
echo Pull the latest updates from repo
echo
git pull
echo
echo Remove the old build folder to make it clean
echo
sudo rm -r -f ./build
echo
echo Running cmake
echo
mkdir build
cd build
cmake .. -DCONF_DIR=/home/conan/Settings -DTOOLS=0 -DWITH_WARNINGS=0
echo
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
