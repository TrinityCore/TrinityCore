UPDATE `realmlist` SET `gamebuild`=32722 WHERE `gamebuild`=32638;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32722';
