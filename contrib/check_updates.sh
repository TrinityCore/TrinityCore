#!/bin/sh
name=$1
database=$2

echo "Database Updater check script:"
echo "  Checking database '${name}' for missing filenames in tables..."
echo

# Select all entries which are in the updates table
entries=$(mysql -uroot ${database} -e "SELECT name FROM updates" | grep ".sql")

cd sql/updates/${name}

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
  echo "- \"sql/updates/${file}\" is missing in table '${name}'.'updates'"
  error=1
 fi
done

if [ ${error} -ne 0 ]
  then
    echo
    echo "Fatal error:"
    echo "  The Database Updater is broken for database '${name}"
    echo "  due to applied update which are missing in the '${name}'.'updates' table."
    echo
    echo "How to fix:"
    echo "  Insert the missing names of sql updates which were applied already to"
    echo "  the 'updates' table of the '${name}' base dump ('sql/base/${name}_database.sql')."
    exit 1
  else
    echo "  Everything is ok, checked ${updates} updates."
    exit 0
fi
