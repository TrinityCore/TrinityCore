ALTER TABLE `groups` CHANGE `isRaid` `groupType` MEDIUMINT(8) UNSIGNED NOT NULL;
UPDATE `groups` SET `groupType`=2 where `groupType`=1;
