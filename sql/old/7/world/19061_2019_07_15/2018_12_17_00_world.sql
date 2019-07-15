-- Pathing for  Entry: 46402 'TDB FORMAT' 
SET @NPC := 264940;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9510.48,`position_y`=-945.682,`position_z`=104.7723 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9510.48,-945.682,104.7723,0,1,0,0,100,0),
(@PATH,2,-9490.02,-945.651,109.2862,0,1,0,0,100,0),
(@PATH,3,-9481.64,-925.976,109.2723,0,1,0,0,100,0),
(@PATH,4,-9464.31,-923.748,112.5456,0,1,0,0,100,0),
(@PATH,5,-9445.52,-922.311,112.5456,0,1,0,0,100,0),
(@PATH,6,-9464.31,-923.748,112.5456,0,1,0,0,100,0),
(@PATH,7,-9481.64,-925.976,109.2723,0,1,0,0,100,0),
(@PATH,8,-9490.02,-945.651,109.2862,0,1,0,0,100,0),
(@PATH,9,-9510.48,-945.682,104.7723,0,1,0,0,100,0),
(@PATH,10,-9533.89,-946.705,104.7548,0,1,0,0,100,0),
(@PATH,11,-9549.63,-945.835,100.3798,0,1,0,0,100,0),
(@PATH,12,-9554.9,-939.823,100.3798,0,1,0,0,100,0),
(@PATH,13,-9560.75,-931.833,100.2973,0,1,0,0,100,0),
(@PATH,14,-9569,-926.535,100.2999,0,1,0,0,100,0),
(@PATH,15,-9575.53,-925.012,100.2999,0,1,0,0,100,0),
(@PATH,16,-9569,-926.535,100.2999,0,1,0,0,100,0),
(@PATH,17,-9560.75,-931.833,100.2973,0,1,0,0,100,0),
(@PATH,18,-9554.9,-939.823,100.3798,0,1,0,0,100,0),
(@PATH,19,-9549.63,-945.835,100.3798,0,1,0,0,100,0),
(@PATH,20,-9533.89,-946.705,104.7548,0,1,0,0,100,0);
-- 0x2030A400202D508000003B0002176446 .go xyz -9510.48 -945.682 104.7723

-- Pathing for  Entry: 46402 'TDB FORMAT' 
SET @NPC := 264918;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9484.29,`position_y`=-969.646,`position_z`=109.2723 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9484.29,-969.646,109.2723,0,0,0,0,100,0),
(@PATH,2,-9469.68,-976.174,109.2723,0,0,0,0,100,0),
(@PATH,3,-9458.85,-979.596,111.0884,0,0,0,0,100,0),
(@PATH,4,-9449.62,-988.665,111.0884,0,0,0,0,100,0),
(@PATH,5,-9442.48,-1009.54,111.0884,0,0,0,0,100,0),
(@PATH,6,-9449.62,-988.665,111.0884,0,0,0,0,100,0),
(@PATH,7,-9458.85,-979.596,111.0884,0,0,0,0,100,0),
(@PATH,8,-9469.68,-976.174,109.2723,0,0,0,0,100,0),
(@PATH,9,-9484.29,-969.646,109.2723,0,0,0,0,100,0),
(@PATH,10,-9508.17,-970.24,104.7574,0,0,0,0,100,0),
(@PATH,11,-9517.24,-974.8,104.7574,0,0,0,0,100,0),
(@PATH,12,-9518.43,-984.09,104.7574,0,0,0,0,100,0),
(@PATH,13,-9517.24,-974.8,104.7574,0,0,0,0,100,0),
(@PATH,14,-9508.17,-970.24,104.7574,0,0,0,0,100,0);
-- 0x203EF000202D50800012DE00038179D8 .go xyz -9484.29 -969.646 109.2723

-- Pathing for  Entry: 48883 'TDB FORMAT' 
SET @NPC := 263867;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9478.011,`position_y`=-956.4583,`position_z`=109.2862 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9478.011,-956.4583,109.2862,0,0,0,0,100,0),
(@PATH,2,-9483.828,-947.7882,109.2862,0,0,0,0,100,0),
(@PATH,3,-9493.745,-946.2916,109.288,0,0,0,0,100,0),
(@PATH,4,-9507.291,-946.875,104.7723,0,0,0,0,100,0),
(@PATH,5,-9527.058,-945.5486,104.7723,0,0,0,0,100,0),
(@PATH,6,-9549.873,-945.8264,100.3798,0,0,0,0,100,0),
(@PATH,7,-9553.707,-951.0538,100.3798,0,0,0,0,100,0),
(@PATH,8,-9555.106,-961.9149,100.3798,0,0,0,0,100,0),
(@PATH,9,-9552.356,-965.5,100.3798,0,0,0,0,100,0),
(@PATH,10,-9544.797,-967.2292,101.4913,0,0,0,0,100,0),
(@PATH,11,-9531.134,-967.6788,104.7574,0,0,0,0,100,0),
(@PATH,12,-9513.389,-968.243,104.7574,0,0,0,0,100,0),
(@PATH,13,-9500.127,-969.6476,107.0643,0,0,0,0,100,0),
(@PATH,14,-9488.435,-969.3143,109.2723,0,0,0,0,100,0),
(@PATH,15,-9479.194,-964.6597,109.2862,0,0,0,0,100,0);
-- 0x2030A400202FBCC000003B0000176451 .go xyz -9478.011 -956.4583 109.2862

DELETE FROM `creature_addon` WHERE `guid` IN (263870, 263868, 263933, 263932, 263921, 263920, 263862, 263860);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(263870, 0, 0, 0, 257, 375, ''),
(263868, 0, 0, 0, 257, 375, ''),
(263933, 0, 0, 0, 257, 375, ''),
(263932, 0, 0, 0, 257, 375, ''),
(263921, 0, 0, 0, 257, 375, ''),
(263920, 0, 0, 0, 257, 375, ''),
(263862, 0, 0, 0, 257, 375, ''),
(263860, 0, 0, 0, 257, 375, '');

-- Creature Ramkahen Citizen 46402 SAI
SET @ENTRY := 46402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

SET @ENTRY := -264447;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264446;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264933;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264934;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264932;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264931;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264938;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264936;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

SET @ENTRY := -264937;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 2000, 10000, 2000, 10000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 2000 and 10000 ms (and later repeats every 2000 and 10000 ms) - Self: Play emote 1 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 20000, 30000, 20000, 30000, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 20000 and 30000 ms (and later repeats every 20000 and 30000 ms) - Self: Play emote 25 // ");

-- Creature Samir 
SET @ENTRY := 47625;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 5000, 5000, 55000, 55000, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 5000 and 5000 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 69 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 0, 12500, 12500, 55000, 55000, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 12500 and 12500 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 0, 13000, 13000, 55000, 55000, 66, 0, 0, 0, 0, 0, 0, 10, 263934, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 13000 and 13000 ms) - Self: Look at Creature Blacksmith Abasi 48617 (263934) // "),
(@ENTRY, 0, 3, 0, 60, 0, 100, 0, 15000, 15000, 55000, 55000, 5, 397, 0, 0, 0, 0, 0, 10, 263934, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 15000 and 15000 ms) - Creature Blacksmith Abasi 48617 (263934): Play emote 397 // "),
(@ENTRY, 0, 4, 0, 60, 0, 100, 0, 15600, 15600, 55000, 55000, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 15600 and 15600 ms) - Self: Play emote 274 // "),
(@ENTRY, 0, 5, 0, 60, 0, 100, 0, 19400, 19400, 55000, 55000, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 19400 and 19400 ms) - Self: Play emote 6 // "),
(@ENTRY, 0, 6, 0, 60, 0, 100, 0, 19700, 19700, 55000, 55000, 5, 396, 0, 0, 0, 0, 0, 10, 263934, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 19700 and 19700 ms) - Creature Blacksmith Abasi 48617 (263934): Play emote 396 // "),
(@ENTRY, 0, 7, 0, 60, 0, 100, 0, 22900, 22900, 55000, 55000, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 22900 and 22900 ms) - Self: Play emote 273 // "),
(@ENTRY, 0, 8, 0, 60, 0, 100, 0, 24500, 24500, 55000, 55000, 5, 396, 0, 0, 0, 0, 0, 10, 263934, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 24500 and 24500 ms) - Creature Blacksmith Abasi 48617 (263934): Play emote 396 // "),
(@ENTRY, 0, 9, 0, 60, 0, 100, 0, 26500, 26500, 55000, 55000, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 26500 and 26500 ms) - Self: Look at home position // "),
(@ENTRY, 0, 10, 0, 60, 0, 100, 0, 27700, 27700, 55000, 55000, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 27700 and 27700 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // "),
(@ENTRY, 0, 11, 0, 60, 0, 100, 0, 31500, 31500, 55000, 55000, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 31500 and 31500 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 233 // "),
(@ENTRY, 0, 12, 0, 60, 0, 100, 0, 49800, 49800, 55000, 55000, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 55000 and 55000 ms (for the first time, timer between 49800 and 49800 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // ");

DELETE FROM `creature_addon` WHERE `guid`= 264935;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(264935, 0, 0, 0, 1, 0, ''); -- 47625

UPDATE `creature` SET `equipment_id`= 1 WHERE `guid`= 264935;

DELETE FROM `creature_equip_template` WHERE `CreatureID`= 47625;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(47625, 1, 1903, 0, 0); -- 47625
