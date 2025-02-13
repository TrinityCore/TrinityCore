UPDATE `realmlist` SET `gamebuild`=57294 WHERE `gamebuild`=57244;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57294';
