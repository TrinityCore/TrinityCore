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

./compile.sh