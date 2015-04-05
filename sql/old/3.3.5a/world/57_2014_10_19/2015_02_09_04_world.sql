--
UPDATE `smart_scripts` SET `action_param1`=1 WHERE  `entryorguid`=27963 AND `source_type`=0 AND `id`=0 AND `link`=0;

DELETE FROM `creature_formations` WHERE `leaderGUID`=126709;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126709, 126709, 0, 0, 2, 0, 0),
(126709, 126692, 4, 50, 2, 0, 0),
(126709, 126693, 4, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126687;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126687, 126687, 0, 0, 2, 0, 0),
(126687, 126705, 3, 50, 2, 0, 0),
(126687, 126700, 3, 310, 2, 0, 0);

UPDATE `creature_addon` SET `path_id`=0 WHERE  `guid` IN (126711, 126701, 126703);
DELETE FROM `creature_formations` WHERE `leaderGUID`=126690;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126690, 126690, 0, 0, 2, 0, 0),
(126690, 126707, 3, 50, 2, 0, 0),
(126690, 126701, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126691;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126691, 126691, 0, 0, 2, 0, 0),
(126691, 126708, 3, 50, 2, 0, 0),
(126691, 126702, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126695;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126695, 126695, 0, 0, 2, 0, 0),
(126695, 126713, 3, 50, 2, 0, 0),
(126695, 126703, 3, 310, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126696;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126696, 126696, 0, 0, 2, 0, 0),
(126696, 126714, 3, 50, 2, 0, 0),
(126696, 126704, 3, 310, 2, 0, 0);

-- Pathing for  Entry: 28582 'TDB FORMAT' 
SET @NPC := 126696; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(1266960, 1, 1180.73, 659.129, 196.233, 0, 0, 0, 0, 100, 3108493),
(1266960, 2, 1181.3, 667.947, 196.233, 0, 0, 0, 0, 100, 3108495),
(1266960, 3, 1180.7, 675.583, 196.235, 0, 0, 0, 0, 100, 3108497),
(1266960, 4, 1177.06, 683.484, 196.235, 0, 0, 0, 0, 100, 3108499),
(1266960, 7, 1180.73, 659.129, 196.233, 0, 0, 0, 0, 100, 3108493),
(1266960, 6, 1181.3, 667.947, 196.233, 0, 0, 0, 0, 100, 3108495),
(1266960, 5, 1180.7, 675.583, 196.235, 0, 0, 0, 0, 100, 3108497),
(1266960, 8, 1177.75, 651.607, 196.235, 0, 0, 0, 0, 100, 3108501);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126715;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126715, 126715, 0, 0, 2, 0, 0),
(126715, 126716, 5, 270, 2, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=126694;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(126694, 126694, 0, 0, 2, 0, 0),
(126694, 126711, 3, 50, 2, 0, 0),
(126694, 126712, 3, 310, 2, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=28055;
-- Dark Rune Shaper SAI
SET @ENTRY := 27965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=14;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,14,0,1,0,100,0,2000,2000,4000,4000,11,50563,0,0,0,0,0,19,28055,50,0,0,0,0,0,"Dark Rune Shaper - On Reset - Cast 'Carve Stone'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=50563;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 50563, 0, 0, 31, 0, 3, 28055, 0, 0, 0, 0, '', 'Carve Stone - only targets Dummy');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=50563;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 50563, 64, '', '', 'Ignore LOS for Carve Stone');

UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `guid` IN (126738, 126745, 126739, 126744);
