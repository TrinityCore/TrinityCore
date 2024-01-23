#!/bin/bash

current_date=$(date "+%Y_%m_%d_%H")

while true; do
    read -p "Enter file name: " file_name

    file_name=${file_name// /_}

    sql_file_name="${current_date}_world_${file_name}.sql"

    if [ -e "$sql_file_name" ]; then
        echo "Error: File '$sql_file_name' already exists. Please choose a different name."
    else
        touch "$sql_file_name"
        echo "Empty SQL file '$sql_file_name' has been generated in the current directory."
        break
    fi
done

read -n 1 -s -r -p "Press any key to exit."
