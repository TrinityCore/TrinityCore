UPDATE `realmlist` SET `gamebuild`=24461 WHERE `gamebuild`=24430;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '24461';
