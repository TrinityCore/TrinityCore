UPDATE `realmlist` SET `gamebuild`=26822 WHERE `gamebuild`=26654;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26822';
