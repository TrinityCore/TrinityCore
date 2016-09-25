UPDATE `realmlist` SET `gamebuild`=22594 WHERE `gamebuild`=22566;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22594';
