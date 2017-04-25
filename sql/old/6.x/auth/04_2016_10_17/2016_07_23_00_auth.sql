UPDATE `realmlist` SET `gamebuild`=22293 WHERE `gamebuild`=22248;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22293';
