UPDATE `realmlist` SET `gamebuild`=22624 WHERE `gamebuild`=22594;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22624';
