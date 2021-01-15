UPDATE `realmlist` SET `gamebuild`=23360 WHERE `gamebuild`=23222;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '23360';
