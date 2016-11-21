UPDATE `realmlist` SET `gamebuild`=22747 WHERE `gamebuild`=22624;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '22624';
