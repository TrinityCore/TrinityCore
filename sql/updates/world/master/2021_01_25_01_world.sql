--
ALTER TABLE `creature`
	ADD COLUMN `spawntimesecmax` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `spawntimesecs`;
