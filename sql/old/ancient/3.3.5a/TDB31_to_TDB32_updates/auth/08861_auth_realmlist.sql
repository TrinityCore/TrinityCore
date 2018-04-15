UPDATE `realmlist` SET `gamebuild`=12340 WHERE `id`=1;
ALTER TABLE `realmlist` CHANGE COLUMN `gamebuild` `gamebuild` int(11) unsigned NOT NULL default '12340';

