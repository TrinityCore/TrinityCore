UPDATE `realmlist` SET `gamebuild`=31229 WHERE `gamebuild`=30993;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '31229';
