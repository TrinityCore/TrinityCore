UPDATE `realmlist` SET `gamebuild`=22522 WHERE `gamebuild`=22498;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22522';
