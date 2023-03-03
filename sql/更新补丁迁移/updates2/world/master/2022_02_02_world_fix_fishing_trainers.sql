/*
**************************
*    BfaCore Reforged    *
**************************
*/


-- Eastern Kingdoms
DELETE FROM `npc_trainer` WHERE `ID` IN (1651,1700,50570,1683,1680,3179,5493,5161,2834,5690,14740,4573,16780);
DELETE FROM `creature_trainer` WHERE `creatureId` IN (1651,1680,1683,1700,2834,3179,4573,5161,5493,5690,14740,16780,50570);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(1651, 10, 0, 0),
(1680, 10, 0, 0),
(1683, 10, 0, 0),
(1700, 10, 0, 0),
(2834, 10, 0, 0),
(3179, 10, 0, 0),
(4573, 10, 0, 0),
(5161, 10, 4742, 0),
(5493, 10, 0, 0),
(5690, 10, 0, 0),
(14740, 10, 7365, 1),
(16780, 10, 0, 0),
(50570, 10, 0, 0);

UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=80 WHERE  `entry` IN (1651,1680,1683,1700,2834,3179,4573,5493,5690,16780,50570);

-- Katoom the Angler
UPDATE `creature_template` SET `gossip_menu_id`=7365 WHERE  `entry`=14740;

DELETE FROM `gossip_menu` WHERE `MenuId`=7365 AND `TextId`=0;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (7365, 0, 35662);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=7365;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7365, 0, 1, 'I would like to buy from you.', 0, 3, 128, 35662),
(7365, 1, 3, 'What can you teach me?', 0, 5, 16, 35662);

-- Kalimdor
DELETE FROM `npc_trainer` WHERE `ID` IN (3607,17101,23896,7946,4156,16774,5941,5938,12961,12032,3332,44975,3028);
DELETE FROM `creature_trainer` WHERE `creatureId` IN (3607,17101,23896,7946,4156,16774,5941,5938,12961,12032,3332,44975,3028);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(3028, 10, 0, 0),
(3332, 10, 0, 0),
(3607, 10, 0, 0),
(4156, 10, 0, 0),
(5938, 10, 0, 0),
(5941, 10, 0, 0),
(7946, 10, 0, 0),
(12032, 10, 0, 0),
(12961, 10, 0, 0),
(16774, 10, 0, 0),
(17101, 10, 7361, 0),
(23896, 10, 8826, 0),
(44975, 10, 7365, 1);

UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=80 WHERE  `entry` IN (3607,7946,16774,5941,5938,12961,12032);
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=82 WHERE  `entry` IN (3028,3332,4156);

UPDATE `creature_template` SET `gossip_menu_id`=7365 WHERE  `entry`=44975;
UPDATE `creature_template` SET `gossip_menu_id`=8826 WHERE  `entry`=23896;