UPDATE `realmlist` SET `gamebuild`=24330 WHERE `gamebuild`=24015;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24330';
