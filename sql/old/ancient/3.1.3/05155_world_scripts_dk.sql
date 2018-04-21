DELETE FROM `creature_questrelation` WHERE `quest` = 12754;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12754;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_questrelation` WHERE `quest` = 12755;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12755);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12755;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (29077, 12755);
DELETE FROM `creature_questrelation` WHERE `quest` = 12756;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (29077, 12756);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12756;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12756);
DELETE FROM `creature_questrelation` WHERE `quest` = 12757;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12757);

UPDATE `quest_template` SET `PrevQuestId`=12751 WHERE `entry`=12754;

update spell_area set quest_end = 12756 where spell=53081;
