UPDATE `realmlist` SET `gamebuild`=22810 WHERE `gamebuild`=22747;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22810';
