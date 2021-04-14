UPDATE `realmlist` SET `gamebuild`=30993 WHERE `gamebuild`=30706;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '30993';
