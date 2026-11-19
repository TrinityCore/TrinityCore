UPDATE `realmlist` SET `gamebuild`=22950 WHERE `gamebuild`=22908;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22950';
