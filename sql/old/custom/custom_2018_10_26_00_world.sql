-- Pathing for  Entry: 54 'TDB FORMAT' 
SET @NPC := 280684;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9464.4,`position_y`=94.0174,`position_z`=58.54224, `orientation`= 0.03490658 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9464.4,94.0174,58.54224,3.159046,13000,0,0,100,0),
(@PATH,2,-9464.4,94.0174,58.54224,0.03490658,24000,0,0,100,0),
(@PATH,3,-9460.3,101.247,58.47567,0,3000,0,0,100,0),
(@PATH,4,-9460.3,101.247,58.47567,1.054814,13000,0,0,100,0),
(@PATH,5,-9464.4,94.0174,58.54224,0,3000,0,0,100,0),
(@PATH,6,-9464.4,94.0174,58.54224,0.03490658,37000,0,0,100,0);
-- 0x203CC80000000D80003C9800004BA8CF .go xyz -9464.4 94.0174 58.54224

-- Creature Corina Steele 54 SAI
SET @ENTRY := 54;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 40, 0, 100, 0, 1, 0, 0, 0, 11, 88424, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 1 of any path reached - Self: Cast spell 88424 on Self // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 4, 0, 0, 0, 11, 88422, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 4 of any path reached - Self: Cast spell 88422 on Self // ");

-- Remove hacky equipment
DELETE FROM `creature_equip_template` WHERE `CreatureID`= 54;

-- Pathing for  Entry: 2046 'TDB FORMAT' 
SET @NPC := 280686;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9464.06,`position_y`=88.934,`position_z`=58.53813 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9464.06,88.934,58.53813,0,1000,0,0,100,0),
(@PATH,2,-9464.06,88.934,58.53813,2.373648,13000,0,0,100,0),
(@PATH,3,-9464.16,87.8281,58.53032,0,1000,0,0,100,0),
(@PATH,4,-9464.16,87.8281,58.53032,0.2268928,28000,0,0,100,0);
-- 0x203CC8000001FF80003C9800004B7B8D .go xyz -9464.06 88.934 58.53813

-- Creature Andrew Krighton 2046 SAI
SET @ENTRY := 2046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 40, 0, 100, 0, 2, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 2 of any path reached - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 233 // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 10000, 10000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 10000 - 10000 ms // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // ");

-- Creature Lyria Du Lac 913 SAI
SET @ENTRY := 913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 7000, 12000, 7000, 12000, 10, 396, 273, 274, 6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 7000 and 12000 ms (for the first time, timer between 7000 and 12000 ms) - Self: Play random emote: 396, 273, 274, 6,  // ");

-- Creature Brother Wilhelm 927 SAI
SET @ENTRY := 927;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 7000, 12000, 7000, 12000, 10, 396, 273, 274, 6, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 7000 and 12000 ms (for the first time, timer between 7000 and 12000 ms) - Self: Play random emote: 396, 273, 274, 6,  // ");

-- Delete obsolete Inkeeper Farley SAI
SET @ENTRY := 295;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Delete obsolete Marshal McBride SAI
SET @ENTRY := 197;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Pathing for  Entry: 797 'TDB FORMAT' 
SET @NPC := 280681;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9427.082,`position_y`=124.8642,`position_z`=59.36305 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9427.082,124.8642,59.36305,0,46000,1,0,100,0),
(@PATH,2,-9446.757,132.8065,58.79227,0,0,1,0,100,0),
(@PATH,3,-9453.114,128.8822,58.91727,0,0,1,0,100,0),
(@PATH,4,-9460.528,123.3364,59.0911,0,0,1,0,100,0),
(@PATH,5,-9465.454,112.1725,57.79227,0,0,1,0,100,0),
(@PATH,6,-9464.705,105.2042,58.28145,0,0,1,0,100,0),
(@PATH,7,-9460.628,94.35499,58.54224,0,46000,1,0,100,0),
(@PATH,8,-9464.572,107.5604,57.637,0,0,1,0,100,0),
(@PATH,9,-9463.494,121.7567,58.65861,0,0,1,0,100,0),
(@PATH,10,-9456.734,126.0858,59.16288,0,0,1,0,100,0),
(@PATH,11,-9444.896,135.8292,58.48393,0,0,1,0,100,0),
(@PATH,12,-9438.719,134.7248,58.30473,0,0,1,0,100,0);
-- 0x203CC8000000C740003C9800004B7B8F .go xyz -9427.082 124.8642 59.36305
