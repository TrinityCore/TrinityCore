#! /bin/bash

clear
echo
echo "######################################"
echo "# Welcome to the SingleCore compiler #"
echo "######################################"
echo
read -n1 -r -p "Press any key to continue..." key

clear
echo Restoring modified files to default.
git reset --hard
echo
echo Pull the latest updates from repo
echo
git pull
echo

chmod +x ./update
chmod +x ./update.sh
chmod +x ./compile.sh
chmod +x ./rebuild
chmod +x ./rebuild.sh
chmod +x ./update-config

sudo rm /usr/local/bin/server-update
sudo cp ./update /usr/local/bin/server-update

sudo rm /usr/local/bin/server-rebuild
sudo cp ./rebuild /usr/local/bin/server-rebuild

sudo rm /usr/local/bin/server-update-config
sudo cp ./update-config /usr/local/bin/server-update-config

./compile.sh