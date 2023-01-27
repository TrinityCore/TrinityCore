UPDATE `realmlist` SET `gamebuild`=30706 WHERE `gamebuild`=28153;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '30706';
