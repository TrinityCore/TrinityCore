ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc1` varchar(100) NOT NULL default '' AFTER name_loc7;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc2` varchar(100) NOT NULL default '' AFTER castbarcaption_loc1;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc3` varchar(100) NOT NULL default '' AFTER castbarcaption_loc2;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc4` varchar(100) NOT NULL default '' AFTER castbarcaption_loc3;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc5` varchar(100) NOT NULL default '' AFTER castbarcaption_loc4;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc6` varchar(100) NOT NULL default '' AFTER castbarcaption_loc5;
ALTER TABLE `locales_gameobject` ADD COLUMN `castbarcaption_loc7` varchar(100) NOT NULL default '' AFTER castbarcaption_loc6;