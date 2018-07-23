UPDATE `realmlist` SET `gamebuild`=26972 WHERE `gamebuild`=26899;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26972';
