UPDATE `realmlist` SET `gamebuild`=23222 WHERE `gamebuild`=23171;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '23222';
