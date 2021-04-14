UPDATE `realmlist` SET `gamebuild`=26124 WHERE `gamebuild`=25996;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '26124';
