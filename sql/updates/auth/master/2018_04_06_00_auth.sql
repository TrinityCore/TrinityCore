UPDATE `realmlist` SET `gamebuild`=26365 WHERE `gamebuild`=26124;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26365';
