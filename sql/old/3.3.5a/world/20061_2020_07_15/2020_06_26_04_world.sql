--
UPDATE `creature_template` SET `speed_walk` = 6.5/2.5, `speed_run` = 10/7, `unit_flags` = 33536, `BaseAttackTime` = 2000, RangeAttackTime = 2000 WHERE `entry` = 23365;
UPDATE `creature_template` SET `speed_run` = 9.7/7 WHERE `entry` = 23380;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.938, `CombatReach` = 1.4 WHERE `DisplayID` = 21433;
UPDATE `creature_model_info` SET `BoundingRadius` = 2.260511 WHERE `DisplayID` = 21444;
UPDATE `spell_target_position` SET `PositionX` = 2330.46, `PositionY` = 7303.28, `PositionZ` = 365.7003, `Orientation` = 3.54216 WHERE `ID` = 41108 AND `EffectIndex` = 0;

-- Torkus SAI
SET @ENTRY := 23316;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,11061,0,0,0,0,11,41109,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Torkus - On Quest 'A Father's Duty' Finished - Cast 'Periodic - Summon Torkus Jr.'");

-- Torkus Jr. SAI
SET @ENTRY := 23365;
UPDATE `creature_template` SET `AIName` = "SmartAI", `flags_extra` = `flags_extra`|512 WHERE `entry` = @ENTRY;
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512  WHERE `entry` = 30813;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ENTRY*100+0 AND @ENTRY*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,0,80,@ENTRY*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Just Summoned - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,12,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,17,0,0,0,0,80,@ENTRY*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Waypoint 17 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,43,0,0,0,0,80,@ENTRY*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Waypoint 43 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,48,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Waypoint 9 Reached - Despawn (1000)"),

(@ENTRY*100+0,9,0,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Orientation Owner"),
(@ENTRY*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 0"),
(@ENTRY*100+0,9,2,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 1"),
(@ENTRY*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Play Emote 92"),
(@ENTRY*100+0,9,4,0,0,0,100,0,0,0,0,0,0,71,0,0,3699,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Change Equipment"),
(@ENTRY*100+0,9,5,0,0,0,100,0,4000,4000,0,0,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Play Emote 92"),
(@ENTRY*100+0,9,6,0,0,0,100,0,0,0,0,0,0,71,0,0,2198,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Change Equipment"),
(@ENTRY*100+0,9,7,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 2"),
(@ENTRY*100+0,9,8,0,0,0,100,0,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Change Equipment"),
(@ENTRY*100+0,9,9,0,0,0,100,0,2000,2000,0,0,0,53,0,23365,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Start Waypoint"),

(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,28000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Pause Waypoint"),
(@ENTRY*100+1,9,1,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Flag Standstate Kneel"),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 3"),
(@ENTRY*100+1,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,19,23334,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 1 (Sky Commander Keller)"),
(@ENTRY*100+1,9,4,0,0,0,100,0,2000,2000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Remove Flag Standstate Kneel"),
(@ENTRY*100+1,9,5,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,19,23334,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Play Emote 1 (Sky Commander Keller)"),
(@ENTRY*100+1,9,6,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 4"),
(@ENTRY*100+1,9,7,0,0,0,100,0,8000,8000,0,0,0,1,2,0,0,0,0,0,19,23334,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 2 (Sky Commander Keller)"),
(@ENTRY*100+1,9,8,0,0,0,100,0,4000,4000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 5"),
(@ENTRY*100+1,9,9,0,0,0,100,0,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 6"),

(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Pause Waypoint"),
(@ENTRY*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 7"),
(@ENTRY*100+2,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,19,22987,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 0 (Skyguard Nether Ray)"),
(@ENTRY*100+2,9,3,0,0,0,100,0,1000,1000,0,0,0,43,0,21444,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Mount"),
(@ENTRY*100+2,9,4,0,0,0,100,0,0,0,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Fly On"),
(@ENTRY*100+2,9,5,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,19,23334,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 3 (Sky Commander Keller)"),

(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,9500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Pause Waypoint"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Dismount"),
(@ENTRY*100+3,9,2,0,0,0,100,0,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Fly Off"),
(@ENTRY*100+3,9,3,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Run On"),
(@ENTRY*100+3,9,4,0,0,0,100,0,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 8"),
(@ENTRY*100+3,9,5,0,0,0,100,0,1000,1000,0,0,0,11,41123,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Cast 'Summon Bronco'"),
(@ENTRY*100+3,9,6,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,23380,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Orientation Closest Creature 'Bronco'"),
(@ENTRY*100+3,9,7,0,0,0,100,0,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Flag Standstate Sit"),
(@ENTRY*100+3,9,8,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,23380,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 0 (Bronco)"),
(@ENTRY*100+3,9,9,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,23380,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Set Data 0 1 (Bronco)"),
(@ENTRY*100+3,9,10,0,0,0,100,0,2000,2000,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Say Line 9"),
(@ENTRY*100+3,9,11,0,0,0,100,0,3000,3000,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Torkus Jr. - On Script - Remove Flag Standstate Sit");

-- Bronco SAI
SET @ENTRY := 23380;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,0,1,0,0,0,53,1,23380,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bronco - On Data Set 0 1 - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,9,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bronco - On Waypoint 9 Reached - Despawn (1000)");

DELETE FROM `waypoints` WHERE `entry` IN (23365,23380);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(23365,1,2388.48,7323.022,366.0821,"Torkus Jr."),
(23365,2,2403.956,7326.238,365.3166,"Torkus Jr."),
(23365,3,2425.602,7328.778,366.0603,"Torkus Jr."),
(23365,4,2456.905,7328.807,364.9909,"Torkus Jr."),
(23365,5,2478.453,7318.382,365.0911,"Torkus Jr."),
(23365,6,2489.64,7319.959,367.9602,"Torkus Jr."),
(23365,7,2499.269,7322.674,371.8641,"Torkus Jr."),
(23365,8,2507.406,7322.218,374.0491,"Torkus Jr."),
(23365,9,2513.396,7324.969,374.6715,"Torkus Jr."),
(23365,10,2506.65,7334.407,376.5914,"Torkus Jr."),
(23365,11,2501.301,7339.496,378.507,"Torkus Jr."),
(23365,12,2502.115,7354.8,380.4968,"Torkus Jr."), --
(23365,13,2501.762,7340.44,378.7509,"Torkus Jr."),
(23365,14,2504.961,7335.365,376.9442,"Torkus Jr."),
(23365,15,2514.731,7329.022,375.3513,"Torkus Jr."),
(23365,16,2523.857,7323.703,373.4666,"Torkus Jr."),
(23365,17,2530.638,7314.663,373.4666,"Torkus Jr."), --
(23365,18,2533.652,7313.149,374.7746,"Torkus Jr."),
(23365,19,2533.447,7316.091,376.6632,"Torkus Jr."),
(23365,20,2533.632,7318.173,374.5524,"Torkus Jr."),
(23365,21,2535.23,7315.936,375.0524,"Torkus Jr."),
(23365,22,2537.44,7314.543,375.5802,"Torkus Jr."),
(23365,23,2537.963,7317.232,375.3579,"Torkus Jr."),
(23365,24,2536.23,7319.043,376.0521,"Torkus Jr."),
(23365,25,2533.874,7320.764,375.08,"Torkus Jr."),
(23365,26,2530.911,7318.042,374.4968,"Torkus Jr."),
(23365,27,2530.487,7316.014,376.4689,"Torkus Jr."),
(23365,28,2528.512,7319.185,375.4412,"Torkus Jr."),
(23365,29,2529.733,7322.888,376.1076,"Torkus Jr."),
(23365,30,2531.962,7323.523,376.4968,"Torkus Jr."),
(23365,31,2537.023,7322.074,376.2847,"Torkus Jr."),
(23365,32,2541.908,7319.018,375.09,"Torkus Jr."),
(23365,33,2547.636,7318.503,375.2287,"Torkus Jr."),
(23365,34,2558.549,7312.783,375.2287,"Torkus Jr."),
(23365,35,2567.508,7306.688,375.2287,"Torkus Jr."),
(23365,36,2575.549,7305.697,378.951,"Torkus Jr."),
(23365,37,2571.671,7308.094,383.7288,"Torkus Jr."),
(23365,38,2561.646,7313.308,387.7843,"Torkus Jr."),
(23365,39,2555.156,7311.284,383.8676,"Torkus Jr."),
(23365,40,2560.29,7306.233,378.8124,"Torkus Jr."),
(23365,41,2563.351,7296.057,378.8124,"Torkus Jr."),
(23365,42,2567.216,7299.937,378.8124,"Torkus Jr."),
(23365,43,2573.686,7298.948,365.813,"Torkus Jr."), --
(23365,44,2593.253,7268.279,364.9899,"Torkus Jr."),
(23365,45,2591.54,7239.053,364.9277,"Torkus Jr."),
(23365,46,2578.906,7225.053,364.9814,"Torkus Jr."),
(23365,47,2574.136,7205.383,364.1418,"Torkus Jr."),
(23365,48,2583.654,7164.126,364.8251,"Torkus Jr."),
(23380,1,2573.233,7295.982,365.5504,"Bronco"),
(23380,2,2591.895,7269.491,364.827,"Bronco"),
(23380,3,2595.734,7247.869,364.185,"Bronco"),
(23380,4,2583.377,7237.241,364.5394,"Bronco"),
(23380,5,2569.756,7223.433,363.8503,"Bronco"),
(23380,6,2575.606,7193.863,363.8637,"Bronco"),
(23380,7,2587.886,7161.841,364.5957,"Bronco"),
(23380,8,2603.697,7122.514,365.4023,"Bronco"),
(23380,9,2607.468,7087.224,365.3389,"Bronco");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23365,22987,23380);
DELETE FROM `creature_text` WHERE `CreatureID` = 23334 AND `GroupID` IN (1,2,3);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(23365,0,0,"Thank you for helping us with the flasks.",12,0,100,1,0,0,21479,0,"Torkus Jr."),
(23365,1,0,"Now that the flasks are ready, we can show the Skyguard our moves!",12,0,100,1,0,0,21445,0,"Torkus Jr."),
(23365,2,0,"Watch out, Skyguard. Here comes Torkus Jr.!",12,0,100,15,0,0,21446,0,"Torkus Jr."),
(23365,3,0,"Commander, sir! Cadet Torkus Jr. reporting for duty, sir!",12,0,100,0,0,0,21447,0,"Torkus Jr."),
(23365,4,0,"Yes, sir. An ogre, sir. But give us a chance, sir! We've been preparing for this since the first time the Skyguard flew over Ogri'la, sir!",12,0,100,1,0,0,21449,0,"Torkus Jr."),
(23365,5,0,"Nonsense!",12,0,100,11,0,0,21488,0,"Torkus Jr."),
(23365,6,0,"%s makes a gesture of dismissal and heads for the launch pad.",16,0,100,0,0,0,21450,0,"Torkus Jr."),
(23365,7,0,"Bronco? That sounds like a good one!",12,0,100,1,0,0,21472,0,"Torkus Jr."),
(23365,8,0,"Bronco bucks %s from its back and escapes into the wild!",16,0,100,0,0,0,21468,0,"Torkus Jr."),
(23365,9,0,"Come back, Mr. Bronco! We're gonna be in the Skyguard together!",14,0,100,15,0,0,21476,0,"Torkus Jr."),
(23334,1,0,"Look here, lad. I admire your dedication, but I'm not sure how to tell you this... You're an ogre, son.",12,0,100,5,0,0,21448,0,"Sky Commander Keller"),
(23334,2,0,"I don't think yer hearin' me. Nether rays just aren't made for --",12,0,100,1,0,0,21473,0,"Sky Commander Keller"),
(23334,3,0,"No, lad, not Bronco! He's not been broken yet! You'll get yerself killed up there!",14,0,100,5,0,0,21467,0,"Sky Commander Keller"),
(22987,0,0,"%s cowers in fear as it realizies what the ogre has in mind.",16,0,100,0,0,0,21451,0,"Skyguard Nether Ray"),
(23380,0,0,"%s hisses loudly at Torkus Jr.",16,0,100,35,0,0,21482,0,"Bronco");
