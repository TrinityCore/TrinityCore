UPDATE `realmlist` SET `gamebuild`=26899 WHERE `gamebuild`=26822;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26899';
