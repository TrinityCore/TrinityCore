UPDATE `realmlist` SET `gamebuild`=24742 WHERE `gamebuild`=24461;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24742';
