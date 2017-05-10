-- Spawn few missing Bloodcursed Voyagers
SET @CGUID := 75068;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 17714, 530, 1, 1, -981.0825, -12847.73, -78.35015, 2.45272, 120, 5, 1), 
(@CGUID+1, 17714, 530, 1, 1, -981.314, -12813.58, -51.96035, 0.8106143, 120, 5, 1), 
(@CGUID+2, 17714, 530, 1, 1, -1135.072, -12931.56, -98.48705, 2.435335, 120, 5, 1), 
(@CGUID+3, 17714, 530, 1, 1, -1119.166, -12949.73, -99.68898, 2.535294, 120, 5, 1), 
(@CGUID+4, 17714, 530, 1, 1, -1151.618, -12952.28, -101.0686, 2.985196, 120, 5, 1),
(@CGUID+5, 17714, 530, 1, 1, -1150.575, -12917.89, -101.5449, 3.950372, 120, 5, 1),
(@CGUID+6, 17714, 530, 1, 1, -1201.324, -12933.42, -102.7079, 1.193372, 120, 5, 1),
(@CGUID+7, 17714, 530, 1, 1, -1183.288, -12912.58, -102.4625, 3.731045, 120, 5, 1),
(@CGUID+8, 17714, 530, 1, 1, -1221.537, -12954.43, -104.158, 4.284279, 120, 5, 1),
(@CGUID+9, 17714, 530, 1, 1, -1252.931, -12952.77, -104.744, 3.633311, 120, 5, 1),
(@CGUID+10, 17714, 530, 1, 1, -1134.563, -12897.89, -102.6108, 2.934096, 120, 5, 1),
(@CGUID+11, 17714, 530, 1, 1, -1147.651, -12879.45, -102.4199, 4.143747, 120, 5, 1),
(@CGUID+12, 17714, 530, 1, 1, -1411.555, -12765.24, -16.17389, 1.595299, 120, 5, 1),
(@CGUID+13, 17714, 530, 1, 1, -1415.727, -12795.06, -15.76654, 1.830911, 120, 5, 1);

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=8298 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `OptionBroadcastTextID`, `npc_option_npcflag`, `box_coded`, `box_money`, `box_text`) VALUES
(8298, 0, 0, 'Can you cast the spell to help me breathe and move underwater?', 1, 19071, 1, 0, 0, ''); -- 17712

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8298;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(15, 8298, 0, 0, 0, 9, 0, 9674, 0, 0, 0, 0, 0, 'Captain Edward Hanes - Show Gossip if player has quest 9674 incomplete'),
(15, 8298, 0, 0, 1, 9, 0, 9682, 0, 0, 0, 0, 0, 'Captain Edward Hanes - Show Gossip if player has quest 9682 incomplete');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 17712 AND `id` IN (1, 2, 3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17712,0,1,2,62,0,100,0,8298,0,0,0,11,31319,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Edward Hanes - On Gossip Select - Cast "The Captain\'s Kiss"'),
(17712,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Edward Hanes - On Gossip Select - Close Gossip'),
(17712,0,3,0,19,0,100,0,9674,0,0,0,11,31319,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Edward Hanes - On Quest Accept - Cast "The Captain\'s Kiss"'),
(17712,0,4,0,19,0,100,0,9682,0,0,0,11,31319,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captain Edward Hanes - On Quest Accept - Cast "The Captain\'s Kiss"');
