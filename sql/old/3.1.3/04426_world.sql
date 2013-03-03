DELETE FROM `creature_questrelation` WHERE `quest` = 12754;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12754;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_questrelation` WHERE `quest` = 12757;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12757);
DELETE FROM `creature_questrelation` WHERE `quest` = 12754;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12754;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12754);
DELETE FROM `creature_questrelation` WHERE `quest` = 12755;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12755);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12756;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (28914, 12756);
DELETE FROM `creature_questrelation` WHERE `quest` = 12757;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (28914, 12757);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12800;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (31082, 12800);
DELETE FROM `creature_questrelation` WHERE `quest` = 12801;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (31082, 12801);
DELETE FROM `creature_involvedrelation` WHERE `quest` = 12801;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES (29173, 12801);
UPDATE `quest_template` SET `PrevQuestId`=13166 WHERE `entry`=13188;
UPDATE `quest_template` SET `PrevQuestId`=13166 WHERE `entry`=13189;

UPDATE `creature` SET `phaseMask`=128 WHERE `id` IN (31082,29173,29199,29204,29200);
-- Citizen of New Avalon
UPDATE creature_template SET unit_flags = 537166336, dynamicflags = 0 WHERE entry = 28942;
