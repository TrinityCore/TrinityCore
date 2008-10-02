ALTER TABLE `gameobject` CHANGE COLUMN `dynflags` `state` int(11) unsigned NOT NULL default '1';
UPDATE `gameobject` SET `state` = 1;
