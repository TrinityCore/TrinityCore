--
DELETE FROM `creature_queststarter` WHERE `quest` IN (24629,24635,24636);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES
(37675,24629),(37675,24635),(37675,24636);
DELETE FROM `creature_questender` WHERE `quest` IN (24629,24635,24636);
INSERT INTO `creature_questender` (`id`,`quest`) VALUES
(37675,24629),(37675,24635),(37675,24636);
