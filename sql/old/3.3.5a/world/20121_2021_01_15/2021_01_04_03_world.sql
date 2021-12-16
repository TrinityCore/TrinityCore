--
SET @CGUID := 147153; -- 20

DELETE FROM `spawn_group_template` WHERE `groupId` IN (100,101);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(100,"Shadowmoon Valley - The Deadliest Trap Ever Laid (Scryers) - Sanctum Defender",4),
(101,"Shadowmoon Valley - The Deadliest Trap Ever Laid (Scryers) - Dragonmaw Skybreaker",4);

DELETE FROM `spawn_group` WHERE `groupId` IN (100,101) AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(100,0,@CGUID+00),
(100,0,@CGUID+01),
(100,0,@CGUID+02),
(100,0,@CGUID+03),
(100,0,@CGUID+04),
(100,0,@CGUID+05),
(100,0,@CGUID+06),
(100,0,@CGUID+07),
(100,0,@CGUID+08),
(100,0,@CGUID+09),
(101,0,@CGUID+10),
(101,0,@CGUID+11),
(101,0,@CGUID+12),
(101,0,@CGUID+13),
(101,0,@CGUID+14),
(101,0,@CGUID+15),
(101,0,@CGUID+16),
(101,0,@CGUID+17),
(101,0,@CGUID+18);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+19 AND `id` IN (23435,23440,23443);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(@CGUID+00, 23435, 530, 1, 1, 0, 1, -4084.223876953125, 1066.301025390625, 31.44091796875, 5.427973747253417968, 300, 0, 0, 15595),
(@CGUID+01, 23435, 530, 1, 1, 0, 1, -4063.517333984375, 1079.0699462890625, 32.32865142822265625, 5.462880611419677734, 300, 0, 0, 15595),
(@CGUID+02, 23435, 530, 1, 1, 0, 1, -4071.4462890625, 1070.081787109375, 30.65686798095703125, 5.358160972595214843, 300, 0, 0, 15595),
(@CGUID+03, 23435, 530, 1, 1, 0, 1, -4064.421875, 1074.611328125, 31.13295936584472656, 5.323254108428955078, 300, 0, 0, 15595),
(@CGUID+04, 23435, 530, 1, 1, 0, 1, -4070.817626953125, 1074.8057861328125, 31.39684104919433593, 5.393067359924316406, 300, 0, 0, 15595),
(@CGUID+05, 23435, 530, 1, 1, 0, 1, -4074.188720703125, 1076.3873291015625, 31.96249771118164062, 5.358160972595214843, 300, 0, 0, 15595),
(@CGUID+06, 23435, 530, 1, 1, 0, 1, -4077.014404296875, 1070.7025146484375, 31.12168502807617187, 5.375614166259765625, 300, 0, 0, 15595),
(@CGUID+07, 23435, 530, 1, 1, 0, 1, -4078.46435546875, 1065.28515625, 31.173919677734375, 5.358160972595214843, 300, 0, 0, 15595),
(@CGUID+08, 23435, 530, 1, 1, 0, 1, -4086.240478515625, 1060.3443603515625, 31.09149932861328125, 5.305800914764404296, 300, 0, 0, 15595),
(@CGUID+09, 23435, 530, 1, 1, 0, 1, -4056.84033203125, 1079.5728759765625, 32.50324630737304687, 5.567600250244140625, 300, 0, 0, 15595),
(@CGUID+10, 23440, 530, 1, 1, 0, 1, -4038.298095703125, 964.6944580078125, 55.94990158081054687, 1.585494875907897949, 10, 0, 2, 15595),
(@CGUID+11, 23440, 530, 1, 1, 0, 1, -4100.36181640625, 963.986083984375, 64.09630584716796875, 1.527074813842773437, 10, 0, 2, 15595),
(@CGUID+12, 23440, 530, 1, 1, 0, 1, -4020.853271484375, 969.527099609375, 61.71982192993164062, 0.872406184673309326, 10, 0, 2, 15595),
(@CGUID+13, 23440, 530, 1, 1, 0, 1, -3999.452880859375, 981.05078125, 50.08077239990234375, 4.272479057312011718, 10, 0, 2, 15595),
(@CGUID+14, 23440, 530, 1, 1, 0, 1, -4063.1064453125, 962.00048828125, 62.1993560791015625, 1.541814088821411132, 10, 0, 2, 15595),
(@CGUID+15, 23440, 530, 1, 1, 0, 1, -4114.291015625, 972.40594482421875, 71.03450775146484375, 1.782856225967407226, 10, 0, 2, 15595),
(@CGUID+16, 23440, 530, 1, 1, 0, 1, -4088.264892578125, 961.55322265625, 60.43377685546875, 1.56161201000213623, 10, 0, 2, 15595),
(@CGUID+17, 23440, 530, 1, 1, 0, 1, -4074.982421875, 961.5074462890625, 55.21341705322265625, 1.431109905242919921, 10, 0, 2, 15595),
(@CGUID+18, 23440, 530, 1, 1, 0, 1, -4050.46630859375, 961.77740478515625, 54.33264923095703125, 1.300352096557617187, 10, 0, 2, 15595),
-- Dragonmaw Raid Credit Marker (Scryers)
-- No idea what it does and why wasn't sniffed in TBC, not summoned
(@CGUID+19, 23443, 530, 1, 1, 21342, 0, -4085.954345703125, 1107.4495849609375, 41.1008148193359375, 6.213372230529785156, 300, 0, 0, 15595);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+10 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+10,(@CGUID+10)*10,20684,0,1,0,3,""),
(@CGUID+11,(@CGUID+11)*10,20684,0,1,0,3,""),
(@CGUID+12,(@CGUID+12)*10,20684,0,1,0,3,""),
(@CGUID+13,(@CGUID+13)*10,20684,0,1,0,3,""),
(@CGUID+14,(@CGUID+14)*10,20684,0,1,0,3,""),
(@CGUID+15,(@CGUID+15)*10,20684,0,1,0,3,""),
(@CGUID+16,(@CGUID+16)*10,20684,0,1,0,3,""),
(@CGUID+17,(@CGUID+17)*10,20684,0,1,0,3,""),
(@CGUID+18,(@CGUID+18)*10,20684,0,1,0,3,"");

DELETE FROM `waypoint_data` WHERE `id` BETWEEN (@CGUID+10)*10 AND (@CGUID+18)*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
((@CGUID+10)*10,1,-4039.0698,991.22235,69.703094,0,0,1,0,0,0),
((@CGUID+10)*10,2,-4044.9453,1026.4785,51.564217,0,0,1,0,0,0),
((@CGUID+10)*10,3,-4046.6675,1054.0055,34.70309,0,0,1,0,0,0),
((@CGUID+10)*10,4,-4054.3298,1074.1635,32.84199,0,50000000,1,0,0,0),
((@CGUID+11)*10,1,-4099.288,981.44794,67.95191,0,0,1,0,0,0),
((@CGUID+11)*10,2,-4094.4888,1028.0123,51.118576,0,0,1,0,0,0),
((@CGUID+11)*10,3,-4088.3276,1055.0275,41.36858,0,50000000,1,0,0,0),
((@CGUID+12)*10,1,-4006.2656,989.791,42.853645,0,0,1,0,0,0),
((@CGUID+12)*10,2,-3996.3499,1025.583,42.853645,0,0,1,0,0,0),
((@CGUID+12)*10,3,-4003.674,1055.279,42.853645,0,0,1,0,0,0),
((@CGUID+12)*10,4,-4028.947,1082.6088,42.853645,0,0,1,0,0,0),
((@CGUID+12)*10,5,-4045.464,1078.8114,39.575867,0,50000000,1,0,0,0),
((@CGUID+13)*10,1,-3990.658,1017.7838,56.139027,0,0,1,0,0,0),
((@CGUID+13)*10,2,-4006.1025,1049.133,55.555695,0,0,1,0,0,0),
((@CGUID+13)*10,3,-4019.0344,1080.7048,35.305683,0,0,1,0,0,0),
((@CGUID+13)*10,4,-4053.2844,1074.483,33.611267,0,50000000,1,0,0,0),
((@CGUID+14)*10,1,-4062.9375,991.71747,43.696457,0,0,1,0,0,0),
((@CGUID+14)*10,2,-4068.4714,1033.1897,43.69646,0,0,1,0,0,0),
((@CGUID+14)*10,3,-4063.366,1066.3694,36.36312,0,50000000,1,0,0,0),
((@CGUID+15)*10,1,-4119.0396,1003.5063,49.8121,0,0,1,0,0,0),
((@CGUID+15)*10,2,-4113.9204,1050.867,36.728764,0,0,1,0,0,0),
((@CGUID+15)*10,3,-4099.3726,1059.4963,33.645435,0,0,1,0,0,0),
((@CGUID+15)*10,4,-4093.058,1059.0251,31.534332,0,50000000,1,0,0,0),
((@CGUID+16)*10,1,-4087.7935,993.5523,54.441216,0,0,1,0,0,0),
((@CGUID+16)*10,2,-4083.7122,1036.6643,35.0801,0,0,1,0,0,0),
((@CGUID+16)*10,3,-4081.1072,1055.6353,31.913435,0,50000000,1,0,0,0),
((@CGUID+17)*10,1,-4071.2063,988.23004,36.30107,0,0,1,0,0,0),
((@CGUID+17)*10,2,-4066.255,1017.4882,29.634405,0,0,1,0,0,0),
((@CGUID+17)*10,3,-4060.89,1066.7999,31.106628,0,50000000,1,0,0,0),
((@CGUID+18)*10,1,-4042.351,995.9251,44.355988,0,0,1,0,0,0),
((@CGUID+18)*10,2,-4043.5217,1043.2762,44.355988,0,0,1,0,0,0),
((@CGUID+18)*10,3,-4053.7783,1066.186,35.717106,0,50000000,1,0,0,0);

-- Sanctum Defender SAI
-- Some spells may be missing
-- They are archers but likes to enter in melee, probably ranged mode with specific distance
SET @ID := 23435;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,257,1000,1000,0,0,0,17,376,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sanctum Defender - Out of Combat - Set Emote State 376 (No Repeat) (No Reset)"),
(@ID,0,1,0,0,0,100,0,0,0,2400,2400,0,11,41440,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sanctum Defender - In Combat CMC - Cast 'Shoot'"),
(@ID,0,2,0,0,0,100,0,15000,20000,15000,20000,0,11,41448,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sanctum Defender - In Combat - Cast 'Multi-Shot'");

DELETE FROM `creature_template_addon` WHERE `entry` = 23435;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`) VALUES
(23435,258);

-- Dragonmaw Skybreaker SAI
SET @ID := 23440;
UPDATE `creature_template` SET `speed_run` = 1.38571425847, `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,10,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - On Respawn - Say Line 1"),
(@ID,0,1,0,4,0,10,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - On Aggro - Say Line 0"),
(@ID,0,2,0,0,0,100,0,0,0,2400,2400,0,11,41440,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - In Combat CMC - Cast 'Shoot'"),
(@ID,0,3,0,0,0,100,0,10000,15000,15000,25000,0,11,36732,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - In Combat - Cast 'Scatter Shot'"),
(@ID,0,4,0,0,0,100,0,10000,20000,15000,15000,0,11,38861,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - In Combat - Cast 'Aimed Shot'"),
(@ID,0,5,0,0,0,100,0,15000,20000,15000,20000,0,11,41448,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - In Combat - Cast 'Multi-Shot'"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,19,23434,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - On Death - Set Counter 1 1 (Commander Hobb)"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Dragonmaw Skybreaker - On Death - Despawn Instant");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 23440;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(23440,1,1,1,0,0,0);

DELETE FROM `creature_text` WHERE `CreatureID` = 23440;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23440,0,0,"For the Dragonmaw!",12,1,100,0,0,0,1937,0,"Dragonmaw Skybreaker"),
(23440,0,1,"Your bones will break under my boot, $r!",12,1,100,0,0,0,1938,0,"Dragonmaw Skybreaker"),
(23440,0,2,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,1939,0,"Dragonmaw Skybreaker"),
(23440,1,0,"KILL THEM ALL!",14,0,100,0,0,0,21655,0,"Dragonmaw Skybreaker"),
(23440,1,1,"BURN IT DOWN!",14,0,100,0,0,0,21656,0,"Dragonmaw Skybreaker");

-- Commander Hobb SAI
SET @ID := 23434;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+6 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Event start 1
(@ID,0,0,0,19,0,100,0,11097,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Quest 'The Deadliest Trap Ever Laid' Taken - Run Script"),

-- People claims event will stop if too much time has passed, real timers are unknown
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,67,1,360000,360000,0,0,100,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Create Timed Event 1"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Active"),
(@ID*100+0,9,2,0,0,0,100,0,3000,3000,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,131,100,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Spawn SpawnGroup 100"),
(@ID*100+0,9,5,0,0,0,100,0,2000,2000,0,0,0,53,1,23434,0,0,0,2,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Start Waypoint"),

-- Event start 2
(@ID,0,1,0,40,0,100,0,2,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Waypoint 2 Reached - Run Script"),

(@ID*100+1,9,0,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.234021425247192382,"Commander Hobb - On Script - Set Orientation"),
(@ID*100+1,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,3500,3500,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.340707302093505859,"Commander Hobb - On Script - Set Orientation"),
(@ID*100+1,9,3,0,0,0,100,0,0,0,0,0,0,5,48,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Play Emote 48"),
(@ID*100+1,9,4,0,0,0,100,0,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Sheath Ranged"),
(@ID*100+1,9,5,0,0,0,100,0,3000,3000,0,0,0,131,101,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Spawn SpawnGroup 101"),

-- Combat
(@ID,0,2,0,0,0,100,0,0,0,2400,2400,0,11,41440,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Commander Hobb - In Combat CMC - Cast 'Shoot'"),
(@ID,0,3,0,0,0,100,0,1000,1000,10000,10000,0,11,38370,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Commander Hobb - In Combat - Cast 'Aimed Shot'"),
(@ID,0,4,0,0,0,100,0,15000,20000,15000,20000,0,11,41448,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Commander Hobb - In Combat - Cast 'Multi-Shot'"),

-- 3 possible scenarios

-- Timed event triggered, time is over, process event end
(@ID,0,5,0,59,0,100,0,1,0,0,0,0,80,@ID*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Timed Event - Run Script"),

-- Allow to execute special events 1 if creature is Out of Combat or Just Reached Home
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Event Phase 1"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,132,100,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Despawn SpawnGroup 100"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,132,101,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Despawn SpawnGroup 101"),

-- Counter of killed creatures is 30, victory, process event end
(@ID,0,6,0,77,0,100,0,1,30,0,0,0,80,@ID*100+3,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Counter Set 1 30 - Run Script"),

-- Allow to execute special events 2 if creature is Out of Combat or Just Reached Home
(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Event Phase 2"),
-- Cancel timed event
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,74,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Remove Timed Event 1"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,132,100,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Despawn SpawnGroup 100"),
(@ID*100+3,9,3,0,0,0,100,0,0,0,0,0,0,132,101,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Despawn SpawnGroup 101"),
(@ID*100+3,9,4,0,0,0,100,0,0,0,0,0,0,11,41454,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Cast 'Quest Complete Dragonmaw Raid'"),

-- Special case 1 to support returning to home in case of loss
(@ID,0,7,0,1,1,100,0,1000,1000,1000,1000,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - Out of Combat - Run Script (Phase 1)"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Event Phase 0"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,1,0,0,0,8,0,0,0,0,-4098.37109375,1118.4312744140625,42.75072097778320312,5.358160972595214843,"Commander Hobb - On Script - Move To Position"),

-- Special case 2 to support returning to home in case of victory
(@ID,0,8,0,1,2,100,0,1000,1000,1000,1000,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - Out of Combat - Run Script (Phase 2)"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Set Event Phase 0"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,0,69,1,0,1,0,0,0,8,0,0,0,0,-4098.37109375,1118.4312744140625,42.75072097778320312,5.358160972595214843,"Commander Hobb - On Script - Move To Position"),
(@ID*100+5,9,2,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Say Line 2"),

-- Creature returned to home position, reset
(@ID,0,9,0,34,0,100,0,8,1,0,0,0,80,@ID*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Reached Point 1 - Run Script"),

(@ID*100+6,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.358160972595214843,"Commander Hobb - On Script - Set Orientation"),
(@ID*100+6,9,1,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Add NPC Flag Questgiver"),
(@ID*100+6,9,2,0,0,0,100,0,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Reset Counter"),
(@ID*100+6,9,3,0,0,0,100,0,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Reset All Scripts"),
(@ID*100+6,9,4,0,0,0,100,0,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Script - Remove Active"),

-- We are dead, despawn groups and say
(@ID,0,10,0,6,0,100,0,0,0,0,0,0,132,100,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Death - Despawn SpawnGroup 100"),
(@ID,0,11,0,6,0,100,0,0,0,0,0,0,132,101,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Death - Despawn SpawnGroup 101"),
(@ID,0,12,0,6,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Commander Hobb - On Death - Say Line 3");

DELETE FROM `creature_text` WHERE `CreatureID` = 23434;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23434,0,0,"Defenders, show these mongrels the fury of a Scryer!",14,0,100,22,0,0,21632,0,"Commander Hobb"),
(23434,1,0,"Stand tall, soldiers. Show them no quarter!",12,0,100,1,0,0,21633,0,"Commander Hobb"),
(23434,2,0,"Victory to the Scryers! The Dragonmaw have been defeated!",14,0,100,0,0,0,21663,0,"Commander Hobb"),
(23434,3,0,"We... are... lost.",14,0,100,0,0,0,21664,0,"Commander Hobb");

DELETE FROM `waypoints` WHERE `entry` = 23434;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(23434,1,-4075.5479,1081.4083,33.411392,0,0,"Commander Hobb"),
(23434,2,-4066.6372,1067.3375,30.307178,0,0,"Commander Hobb");

UPDATE `creature` SET `position_x` = -4098.37109375, `position_y` = 1118.4312744140625, `position_z` = 42.75072097778320312, `orientation` = 5.358160972595214843, `VerifiedBuild` = 15595 WHERE `id` = 23434;
