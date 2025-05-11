UPDATE `realmlist` SET `gamebuild`=60142 WHERE `gamebuild`=59069;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60142';
