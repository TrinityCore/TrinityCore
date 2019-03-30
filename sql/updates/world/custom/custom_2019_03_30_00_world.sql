UPDATE `access_requirement` SET `quest_failed_text`= '0';
ALTER TABLE `access_requirement` CHANGE `quest_failed_text` `heroic_exclusive` TINYINT(1) DEFAULT 0 NULL;

DELETE FROM `access_requirement` WHERE `mapId` IN (859, 568, 938, 939, 940) AND `difficulty`= 0;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `heroic_exclusive`, `comment`) VALUES
(859, 0, 1, 'Zul''Gurub - Heroic Exclusive'),
(568, 0, 1, 'Zul''Aman - Heroic Exclusive'),
(938, 0, 1, 'End Time - Heroic Exclusive'),
(939, 0, 1, 'Well of Eternity - Heroic Exclusive'),
(940, 0, 1, 'Hour of Twilight - Heroic Exclusive');
