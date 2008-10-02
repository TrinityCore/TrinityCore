-- tinyint can only hold values up to 255 - too small for a waittime in milliseconds
ALTER TABLE `creature_movement` CHANGE COLUMN `waittime` `waittime` int(5) unsigned NOT NULL default '0';