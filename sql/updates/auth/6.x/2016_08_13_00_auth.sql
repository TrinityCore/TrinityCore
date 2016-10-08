UPDATE `realmlist` SET `gamebuild`=22423 WHERE `gamebuild`=22410;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22423';
