UPDATE `realmlist` SET `gamebuild`=68275 WHERE `gamebuild`=68367;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68275';
