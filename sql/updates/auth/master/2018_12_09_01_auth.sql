UPDATE `account` SET `expansion`=7 WHERE `expansion`=6;

ALTER TABLE `account` CHANGE `expansion` `expansion` tinyint(3) unsigned NOT NULL DEFAULT '7';

UPDATE `realmlist` SET `gamebuild`=28153 WHERE `gamebuild`=26972;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '28153';
