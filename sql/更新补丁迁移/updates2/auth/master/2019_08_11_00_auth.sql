UPDATE `realmlist` SET `gamebuild`=31429 WHERE `gamebuild`=31229;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '31429';
