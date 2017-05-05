UPDATE `realmlist` SET `gamebuild`=23937 WHERE `gamebuild`=23911;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '23937';
