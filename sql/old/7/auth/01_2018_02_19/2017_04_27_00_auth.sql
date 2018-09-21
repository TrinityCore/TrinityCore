UPDATE `realmlist` SET `gamebuild`=24015 WHERE `gamebuild`=23937;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24015';
