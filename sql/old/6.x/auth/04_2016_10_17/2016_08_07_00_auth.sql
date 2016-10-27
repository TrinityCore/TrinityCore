UPDATE `realmlist` SET `gamebuild`=22345 WHERE `gamebuild`=22293;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22345';
