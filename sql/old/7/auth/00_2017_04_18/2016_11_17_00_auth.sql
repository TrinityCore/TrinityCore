UPDATE `realmlist` SET `gamebuild`=22996 WHERE `gamebuild`=22995;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22996';
