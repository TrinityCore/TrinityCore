UPDATE `realmlist` SET `gamebuild`=24415 WHERE `gamebuild`=24367;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24415';
