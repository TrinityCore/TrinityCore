UPDATE `realmlist` SET `gamebuild`=23171 WHERE `gamebuild`=22996;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '23171';
