UPDATE `realmlist` SET `gamebuild`=21463 WHERE `gamebuild`=21355;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '21463';
