UPDATE `realmlist` SET `gamebuild`=44061 WHERE `gamebuild`=44015;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '44061';
