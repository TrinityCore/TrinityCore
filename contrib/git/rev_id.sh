#/bin/bash
command=$(git describe --match init --abbrev=12)
IFS="-"
cmdarray=($command)

if [ "$1" != "-id" ] && [ "$1" != "-hash" ]; then
  echo "Usage: $0 <-id | -hash>"
  exit
fi

if [ "${cmdarray[1]}" == "" ] || [ "${cmdarray[2]}" == "" ]; then
  echo "Error: No valid revision information found"
  exit 1
fi

if [ "$1" == "-id" ]; then
  echo ${cmdarray[1]}
elif [ "$1" == "-hash" ]; then
  echo ${cmdarray[2]:1}
fi
