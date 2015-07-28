-- complete quest related stuff in silithus
-- noogle lies on the ground
DELETE FROM `creature_addon` WHERE `guid`=362561;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(362561,0,0,3,1,0, '');

-- teleporter position
DELETE FROM `spell_target_position` WHERE `id`=93726;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES 
(93726, 0, 0, -10878, -2683.63, 9.61432, 0.691772, 0);

UPDATE `creature_template` SET `gossip_menu_id`=6687 WHERE  `entry`=15612;
DELETE FROM `gossip_menu` WHERE `entry`=6687;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (6687, 8059);

-- Beetix Ficklespragg SAI
SET @ENTRY := 15189;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,8278,0,0,0,1,0,0,0,0,0,0,19,15190,20,0,0,0,0,0,"Beetix Ficklespragg - On Quest 'Noggle's Last Hope' Finished - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,5000,5000,20000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Beetix Ficklespragg - Out of Combat - Say Line 0");

-- Noggle Ficklespragg SAI
SET @ENTRY := 15190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,8282,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Quest 'Noggle's Lost Satchel' Finished - Say Line 1");

DELETE FROM `creature_text` WHERE `entry` IN (15190, 15189);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(15190, 0, 0, 'Yes! I\'m cured!  I\'m cure... whoa, got up too fast!', 12, 0, 100, 0, 0, 0, 10675, 0, ''),
(15190, 1, 0, 'Thanks for finding my reagents!  *yawn*  That poison\'s made me... a bit tired...', 12, 0, 100, 0, 0, 0, 10676, 0, ''),
(15189, 0, 0, 'You were always the troublemaker in the family, Noggle.  Always!', 12, 0, 100, 0, 0, 0, 10751, 0, '');

-- Commander Mar'alith SAI
SET @ENTRY := 15181;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,8304,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Commander Mar'alith - On Quest 'Dearest Natalia' Taken - Say Line 0");

DELETE FROM `creature_text` WHERE `entry` IN (15181);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(15181, 0, 0, 'Take this enchanted shard, $n. I will be able to hear the dwarves myself through its twin.', 12, 0, 100, 0, 0, 0, 50667, 0, '');

-- Pathing for  Entry: 11804 'TDB FORMAT' 
SET @NPC := 362751;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6942.874,`position_y`=1110.533,`position_z`=0.7047257 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6942.874,1110.533,0.7047257,0,0,0,0,100,0),
(@PATH,2,-6950.666,1104.255,0.8397331,0,0,0,0,100,0),
(@PATH,3,-6950.607,1104.366,0.5897331,0,0,0,0,100,0),
(@PATH,4,-6950.251,1104.682,0.8397331,0,0,0,0,100,0),
(@PATH,5,-6942.69,1110.832,0.8038445,0,0,0,0,100,0),
(@PATH,6,-6937.58,1115.91,1.38085,0,0,0,0,100,0),
(@PATH,7,-6934.83,1118.41,1.88085,0,0,0,0,100,0),
(@PATH,8,-6932.83,1120.41,2.38085,0,0,0,0,100,0),
(@PATH,9,-6932.487,1120.662,2.760576,0,0,0,0,100,0),
(@PATH,10,-6931.737,1121.412,2.760576,0,0,0,0,100,0),
(@PATH,11,-6929.237,1124.162,3.510576,0,0,0,0,100,0),
(@PATH,12,-6929.332,1124.039,3.269823,0,0,0,0,100,0),
(@PATH,13,-6932.028,1121.268,2.675391,0,0,0,0,100,0),
(@PATH,14,-6933.528,1119.768,2.175391,0,0,0,0,100,0),
(@PATH,15,-6935.278,1118.018,1.675391,0,0,0,0,100,0),
(@PATH,16,-6937.735,1115.59,1.140587,0,0,0,0,100,0),
(@PATH,17,-6943.003,1110.408,0.6729961,0,0,0,0,100,0),
(@PATH,18,-6950.686,1104.583,0.8397331,0,0,0,0,100,0);

-- Pathing for  Entry: 11803 'TDB FORMAT' 
SET @NPC := 363467;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-7963.382,`position_y`=1977.28,`position_z`=6.844955 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7963.382,1977.28,6.844955,0,0,0,0,100,0),
(@PATH,2,-7964.632,1977.03,7.094955,0,0,0,0,100,0),
(@PATH,3,-7972.582,1976.436,7.295979,0,0,0,0,100,0),
(@PATH,4,-7977.582,1973.686,6.795979,0,0,0,0,100,0),
(@PATH,5,-7973.047,1976.35,7.348126,0,0,0,0,100,0),
(@PATH,6,-7972.883,1976.539,7.290794,0,0,0,0,100,0),
(@PATH,7,-7972.383,1976.539,7.290794,0,0,0,0,100,0),
(@PATH,8,-7964.361,1977.418,7.03627,0,0,0,0,100,0),
(@PATH,9,-7960.611,1977.668,6.53627,0,0,0,0,100,0),
(@PATH,10,-7960.552,1977.869,6.533808,0,0,0,0,100,0),
(@PATH,11,-7957.052,1978.119,6.283808,0,0,0,0,100,0),
(@PATH,12,-7957.295,1977.961,6.037067,0,0,0,0,100,0),
(@PATH,13,-7957.259,1978.09,6.310391,0,0,0,0,100,0),
(@PATH,14,-7963.009,1977.59,6.810391,0,0,0,0,100,0),
(@PATH,15,-7964.595,1977.169,6.948967,0,0,0,0,100,0);

-- Mistress Natalia Mar'alith SAI
SET @ENTRY := 15215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar'alith - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,10000,12000,11,44415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress Natalia Mar'alith - In Combat - Cast 'Blackout'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mistress Natalia Mar'alith - Between 0-50% Health - Cast 'Psychic Scream' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,12000,16000,16000,24000,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistress Natalia Mar'alith - In Combat - Cast 'Shadow Word: Pain'");

DELETE FROM `creature_text` WHERE `entry` IN (15215);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(15215, 0, 0, 'Take this enchanted shard, $n. I will be able to hear the dwarves myself through its twin.', 12, 0, 100, 0, 0, 0, 10742, 0, '');
