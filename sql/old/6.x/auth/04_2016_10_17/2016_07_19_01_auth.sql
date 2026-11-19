UPDATE `realmlist` SET `gamebuild`=22248 WHERE `gamebuild`=21742;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22248';
