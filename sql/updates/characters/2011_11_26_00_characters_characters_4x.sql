ALTER TABLE `characters`
DROP COLUMN `todayHonorPoints`,
DROP COLUMN `yesterdayHonorPoints`,
DROP COLUMN `knownCurrencies`,
CHANGE COLUMN `arenaPoints` `conquestPoints` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `taxi_path`;
