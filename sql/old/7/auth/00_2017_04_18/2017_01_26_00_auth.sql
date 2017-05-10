UPDATE `realmlist` SET `gamebuild`=23420 WHERE `gamebuild`=23360;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '23420';
