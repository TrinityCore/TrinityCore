UPDATE `realmlist` SET `gamebuild`=21676 WHERE `gamebuild`=21463;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '21676';
