UPDATE `realmlist` SET `gamebuild`=22995 WHERE `gamebuild`=22950;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22995';
