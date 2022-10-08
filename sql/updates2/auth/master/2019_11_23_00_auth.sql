UPDATE `realmlist` SET `gamebuild`=32638 WHERE `gamebuild`=32580;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32638';
