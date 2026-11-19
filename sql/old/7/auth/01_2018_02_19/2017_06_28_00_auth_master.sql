UPDATE `realmlist` SET `gamebuild`=24430 WHERE `gamebuild`=24415;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24430';
