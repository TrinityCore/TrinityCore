UPDATE `realmlist` SET `gamebuild`=32305 WHERE `gamebuild`=31478;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '32305';
