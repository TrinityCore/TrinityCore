UPDATE `realmlist` SET `gamebuild`=47871 WHERE `gamebuild`=47657;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '47871';