UPDATE `realmlist` SET `gamebuild`=24367 WHERE `gamebuild`=24330;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24367';
