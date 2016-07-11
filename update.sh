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
echo
sudo rm -r -f ./build
mkdir build
cd build
cmake .. -DCONF_DIR=/home/conan/Settings -DTOOLS=0 -DWITH_WARNINGS=0

echo
echo "»»» Debian fix «««"
rm -f "./src/server/worldserver/CMakeFiles/worldserver.dir/link.txt"
cp "../cmake/link.txt" "./src/server/worldserver/CMakeFiles/worldserver.dir"
echo

make -j4
echo
read -n1 -r -p "Press any key to continue..." key

clear
sudo make install
cd ..
