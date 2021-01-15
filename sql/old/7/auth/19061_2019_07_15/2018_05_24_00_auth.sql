UPDATE `realmlist` SET `gamebuild`=26654 WHERE `gamebuild`=26365;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26654';
