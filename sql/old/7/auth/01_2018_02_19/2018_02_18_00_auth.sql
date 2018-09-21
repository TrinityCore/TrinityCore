UPDATE `realmlist` SET `gamebuild`=25996 WHERE `gamebuild`=25549;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '25996';
