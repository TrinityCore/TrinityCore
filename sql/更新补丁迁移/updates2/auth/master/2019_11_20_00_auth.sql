UPDATE `realmlist` SET `gamebuild`=32580 WHERE `gamebuild`=32494;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32580';
