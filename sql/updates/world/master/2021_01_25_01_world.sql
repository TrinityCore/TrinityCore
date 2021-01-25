--
ALTER TABLE `creature`
	ADD COLUMN `spawnTimeSecMax` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `spawntimesecs`;
