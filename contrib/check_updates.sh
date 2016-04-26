#!/bin/sh
name=$1
branch=$2
database=$3

echo "Database Updater check script:"
echo "  Checking database '${name}' for missing filenames in tables..."
echo

# Select all entries which are in the updates table
entries=$(mysql -uroot ${database} -e "SELECT name FROM updates" | grep ".sql")

cd sql/updates/${name}/${branch}

error=0
updates=0

for file in *.sql
do
 # Check if the given update is in the `updates` table.
 if echo "${entries}" | grep -q "^${file}"; then
  # File is ok
  updates=$((updates+1))
 else
  # The update isn't listed in the updates table of the given database.
  echo "- \"sql/updates/${name}/${file}\" is missing in the '${name}'.'updates' table."
  error=1
 fi
done

if [ ${error} -ne 0 ]
  then
    echo
    echo "Fatal error:"
    echo "  The Database Updater is broken for the '${name}' database,"
    echo "  because the applied update is missing in the '${name}'.'updates' table."
    echo
    echo "How to fix:"
    echo "  Insert the missing names of the already applied sql updates"
    echo "  to the 'updates' table of the '${name}' base dump ('sql/base/${name}_database.sql')."
    exit 1
  else
    echo "  Everything is OK, finished checking ${updates} updates."
    exit 0
fi
