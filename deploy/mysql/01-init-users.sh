#!/bin/bash
# Runs inside the mysql container via docker-entrypoint-initdb.d. Uses
# TC_DB_USER / TC_DB_PASSWORD (set in compose.yml from .env) so the DB
# user actually matches what worldserver.conf / authserver.conf connect
# with, instead of a second hardcoded credential.
set -euo pipefail

: "${TC_DB_USER:?TC_DB_USER must be set}"
: "${TC_DB_PASSWORD:?TC_DB_PASSWORD must be set}"

mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" <<-SQL
	CREATE DATABASE IF NOT EXISTS auth CHARACTER SET utf8;
	CREATE DATABASE IF NOT EXISTS characters CHARACTER SET utf8;
	CREATE DATABASE IF NOT EXISTS world CHARACTER SET utf8;

	CREATE USER IF NOT EXISTS '${TC_DB_USER}'@'%' IDENTIFIED BY '${TC_DB_PASSWORD}';
	GRANT ALL PRIVILEGES ON auth.* TO '${TC_DB_USER}'@'%';
	GRANT ALL PRIVILEGES ON characters.* TO '${TC_DB_USER}'@'%';
	GRANT ALL PRIVILEGES ON world.* TO '${TC_DB_USER}'@'%';
	FLUSH PRIVILEGES;
SQL
