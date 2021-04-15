UPDATE `realmlist` SET `gamebuild`=22498 WHERE `gamebuild`=22423;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22498';
