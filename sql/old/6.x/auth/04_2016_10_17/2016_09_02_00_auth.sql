UPDATE `realmlist` SET `gamebuild`=22566 WHERE `gamebuild`=22522;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22566';
