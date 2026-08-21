-- Bootstrap: create the databases and application user TrinityCore expects.
-- Matches the connection strings in deploy/worldserver.conf and deploy/authserver.conf.
CREATE DATABASE IF NOT EXISTS auth CHARACTER SET utf8;
CREATE DATABASE IF NOT EXISTS characters CHARACTER SET utf8;
CREATE DATABASE IF NOT EXISTS world CHARACTER SET utf8;

CREATE USER IF NOT EXISTS 'trinity'@'%' IDENTIFIED BY 'trinity';
GRANT ALL PRIVILEGES ON auth.* TO 'trinity'@'%';
GRANT ALL PRIVILEGES ON characters.* TO 'trinity'@'%';
GRANT ALL PRIVILEGES ON world.* TO 'trinity'@'%';
FLUSH PRIVILEGES;
