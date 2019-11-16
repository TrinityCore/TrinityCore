UPDATE `realmlist` SET `gamebuild`=32494 WHERE `gamebuild`=32305;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32494';
