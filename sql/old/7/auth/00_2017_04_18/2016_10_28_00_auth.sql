UPDATE `realmlist` SET `gamebuild`=22908 WHERE `gamebuild`=22900;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22908';
