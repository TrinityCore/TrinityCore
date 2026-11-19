UPDATE `realmlist` SET `gamebuild`=22410 WHERE `gamebuild`=22345;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22410';
