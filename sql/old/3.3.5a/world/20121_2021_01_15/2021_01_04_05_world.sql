-- Pretty sure some parts are scripted differently, since there are multiple inlvolved creatures it's hard to say
-- what exactly triggers certain events, are they asynchronous or not. Some timers seems to be wrong, even 0.5 sec
-- delay significantly changes event
-- There is area trigger 4883, purpose unk
UPDATE `spell_target_position` SET `PositionX` = 3646.74, `PositionY` = 5893.2, `PositionZ` = 174.483, `Orientation` = 0.698131978511810302, `VerifiedBuild` = 12340 WHERE `ID` = 46018;

UPDATE `quest_template_addon` SET `SourceSpellID` = 0 WHERE `ID` = 11681;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -45992;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-45992,45883,0,"Taxi - Amber Ledge to Beryl Point Platform - On Aura Removed - Target - Cast 'Amber Ledge to Beryl Point'");

-- Warmage Anzim SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25356 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2535600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25356,0,0,0,19,0,100,0,11681,0,0,0,0,80,2535600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Anzim - On Quest 'Rescuing Evanor' Taken - Run Script"),

(2535600,9,0,0,0,0,100,0,0,0,0,0,0,11,45992,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Warmage Anzim - On Script - Cast 'Taxi - Amber Ledge to Beryl Point Platform'"),
(2535600,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Anzim - On Script - Say Line 0"),
(2535600,9,2,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,19,27888,50,0,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1 (Warmage Archus)"),
(2535600,9,3,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,25727,50,0,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1 (Warmage Moran)"),
(2535600,9,4,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,25732,50,0,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1 (Warmage Preston)"),
(2535600,9,5,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,25733,50,0,0,0,0,0,0,"Warmage Anzim - On Script - Set Data 1 1 (Warmage Austin)");

-- Taking Wing Timer Bunny and Anzim Controller Bunny should be used instead
-- For some reason Taking Wing Timer Bunny wasn't spawned at all in sniff
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 25356 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,25356,0,0,29,0,27888,50,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Warmage Archus' is within 50 yards"),
(22,1,25356,0,0,29,0,25727,50,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Warmage Moran' is within 50 yards"),
(22,1,25356,0,0,29,0,25732,50,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Warmage Preston' is within 50 yards"),
(22,1,25356,0,0,29,0,25733,50,0,0,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Warmage Austin' is within 50 yards");

-- Warmage Archus SAI
SET @ID := 27888;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,1,1,0,0,0,53,1,27888,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Archus - On Data Set 1 1 - Start Waypoint"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Archus - On Data Set 1 1 - Set Active On"),
(@ID,0,2,0,40,0,100,0,12,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Archus - On Waypoint 12 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,14,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Archus - On Waypoint 14 Reached - Run Script"),

-- This one arrives first, waits arrival of other and forces them to continue movement
(@ID*100+0,9,0,0,0,0,100,0,7000,7000,0,0,0,45,1,2,0,0,0,0,19,25727,0,0,0,0,0,0,0,"Warmage Archus - On Script - Set Data 1 2 (Warmage Moran)"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,19,25732,0,0,0,0,0,0,0,"Warmage Archus - On Script - Set Data 1 2 (Warmage Preston)"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,19,25733,0,0,0,0,0,0,0,"Warmage Archus - On Script - Set Data 1 2 (Warmage Austin)"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Archus - On Script - Say Line 0"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Archus - On Script - Cast 'Warmage Drake Fireball'"),
(@ID*100+1,9,2,0,0,0,100,0,6000,6000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Archus - On Script - Cast 'Warmage Drake Fireball'"),
(@ID*100+1,9,3,0,0,0,100,0,6000,6000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Archus - On Script - Cast 'Warmage Drake Fireball'");

DELETE FROM `waypoints` WHERE `entry` = 27888;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(27888,1,3455.625,5893.702,147.46953,0,0,"Warmage Archus"),
(27888,2,3444.9219,5897.1685,149.60324,0,0,"Warmage Archus"),
(27888,3,3429.8596,5901.5566,152.02946,0,0,"Warmage Archus"),
(27888,4,3404.945,5908.6284,156.36287,0,0,"Warmage Archus"),
(27888,5,3367.2473,5916.6626,161.72395,0,0,"Warmage Archus"),
(27888,6,3340.2002,5924.8774,164.69623,0,0,"Warmage Archus"),
(27888,7,3313.7268,5936.971,164.72398,0,0,"Warmage Archus"),
(27888,8,3274.5618,5960.1597,163.11285,0,0,"Warmage Archus"),
(27888,9,3248.3792,5984.673,155.39067,0,0,"Warmage Archus"),
(27888,10,3220.3267,6007.317,146.02954,0,0,"Warmage Archus"),
(27888,11,3200.061,6032.292,137.2518,0,0,"Warmage Archus"),
(27888,12,3199.989,6061.957,123.27971,0,7000,"Warmage Archus"), --
(27888,13,3200.0925,6071.211,141.77905,0,0,"Warmage Archus"),
(27888,14,3200.9895,6074.8984,144.97356,0,13000,"Warmage Archus"), --
(27888,15,3209.1426,6061.523,141.88358,0,0,"Warmage Archus"),
(27888,16,3222.4565,6044.5776,176.49445,0,0,"Warmage Archus"),
(27888,17,3235.9856,6025.278,198.77245,0,0,"Warmage Archus");

DELETE FROM `creature_text` WHERE `CreatureID` = 27888;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27888,0,0,"For Dalaran! Attack!",14,0,100,0,0,0,24890,0,"Warmage Archus");

-- Warmage Preston SAI
SET @ID := 25732;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,1,1,0,0,0,53,1,25732,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Preston - On Data Set 1 1 - Start Waypoint"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Preston - On Data Set 1 1 - Set Active On"),
(@ID,0,2,0,38,0,100,0,1,2,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Preston - On Data Set 1 2 - Resume Waypoint"),
(@ID,0,3,0,40,0,100,0,15,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Preston - On Waypoint 15 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,13,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Preston - On Waypoint 13 Reached - Pause Waypoint"),

(@ID*100+0,9,0,0,0,0,100,0,5000,5000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Preston - On Script - Cast 'Warmage Drake Fireball'"),
(@ID*100+0,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Preston - On Script - Cast 'Warmage Drake Fireball'");

DELETE FROM `waypoints` WHERE `entry` = 25732;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(25732,1,3442.4233,5890.586,151.80292,0,0,"Warmage Preston"),
(25732,2,3428.3008,5898.2583,152.02946,0,0,"Warmage Preston"),
(25732,3,3404.945,5908.6284,156.36287,0,0,"Warmage Preston"),
(25732,4,3367.2473,5916.6626,161.72395,0,0,"Warmage Preston"),
(25732,5,3340.2002,5924.8774,164.69623,0,0,"Warmage Preston"),
(25732,6,3313.7268,5936.971,164.72398,0,0,"Warmage Preston"),
(25732,7,3274.5618,5960.1597,163.11285,0,0,"Warmage Preston"),
(25732,8,3248.5293,5977.7803,155.39067,0,0,"Warmage Preston"),
(25732,9,3245.32,6007.739,146.02954,0,0,"Warmage Preston"),
(25732,10,3260.1267,6034.221,131.44637,0,0,"Warmage Preston"),
(25732,11,3256.6243,6055.6704,131.44637,0,0,"Warmage Preston"),
(25732,12,3247.428,6068.3037,130.3353,0,0,"Warmage Preston"),
(25732,13,3232.0784,6079.069,124.50193,0,0,"Warmage Preston"), --
(25732,14,3231.549,6079.4277,132.86238,0,0,"Warmage Preston"),
(25732,15,3224.7488,6083.0376,147.5568,0,14000,"Warmage Preston"), --
(25732,16,3230.0708,6064.604,141.88358,0,0,"Warmage Preston"),
(25732,17,3235.9856,6025.278,235.91063,0,0,"Warmage Preston"),
(25732,18,3250.0664,6003.68,299.3278,0,0,"Warmage Preston"),
(25732,19,3277.5513,5971.299,338.18866,0,0,"Warmage Preston");

-- Warmage Austin SAI
SET @ID := 25733;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,1,1,0,0,0,53,1,25733,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Austin - On Data Set 1 1 - Start Waypoint"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Austin - On Data Set 1 1 - Set Active On"),
(@ID,0,2,0,38,0,100,0,1,2,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Austin - On Data Set 1 2 - Resume Waypoint"),
(@ID,0,3,0,40,0,100,0,18,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Austin - On Waypoint 18 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,16,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Austin - On Waypoint 13 Reached - Pause Waypoint"),

(@ID*100+0,9,0,0,0,0,100,0,3000,3000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Austin - On Script - Cast 'Warmage Drake Fireball'"),
(@ID*100+0,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Austin - On Script - Cast 'Warmage Drake Fireball'");

DELETE FROM `waypoints` WHERE `entry` = 25733;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(25733,1,3423.0476,5891.1543,151.80273,0,0,"Warmage Austin"),
(25733,2,3414.578,5894.0923,149.60324,0,0,"Warmage Austin"),
(25733,3,3399.283,5899.8457,152.02946,0,0,"Warmage Austin"),
(25733,4,3383.5579,5907.456,156.36287,0,0,"Warmage Austin"),
(25733,5,3363.4604,5915.892,161.72395,0,0,"Warmage Austin"),
(25733,6,3340.2002,5924.8774,164.69623,0,0,"Warmage Austin"),
(25733,7,3313.7268,5936.971,164.72398,0,0,"Warmage Austin"),
(25733,8,3274.5618,5960.1597,163.11285,0,0,"Warmage Austin"),
(25733,9,3248.3792,5984.673,155.39067,0,0,"Warmage Austin"),
(25733,10,3242.2053,6019.475,146.02954,0,0,"Warmage Austin"),
(25733,11,3258.1528,6062.04,137.2518,0,0,"Warmage Austin"),
(25733,12,3268.7927,6084.862,131.44637,0,0,"Warmage Austin"),
(25733,13,3266.5671,6115.484,131.44637,0,0,"Warmage Austin"),
(25733,14,3249.3186,6131.7163,131.44637,0,0,"Warmage Austin"),
(25733,15,3230.5322,6123.678,128.8631,0,0,"Warmage Austin"),
(25733,16,3225.4934,6115.8145,127.02973,0,0,"Warmage Austin"), --
(25733,17,3225.812,6111.0366,143.61238,0,0,"Warmage Austin"),
(25733,18,3224.3362,6105.71,146.77905,0,13000,"Warmage Austin"), --
(25733,19,3244.6826,6099.2446,133.1058,0,0,"Warmage Austin"),
(25733,20,3247.6614,6067.4385,179.46667,0,0,"Warmage Austin"),
(25733,21,3245.7947,6032.932,214.77235,0,0,"Warmage Austin"),
(25733,22,3259.2083,5997.6973,236.60551,0,0,"Warmage Austin");

-- Warmage Moran SAI
SET @ID := 25727;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,38,0,100,0,1,1,0,0,0,53,1,25727,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Moran - On Data Set 1 1 - Start Waypoint"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Moran - On Data Set 1 1 - Set Active On"),
(@ID,0,2,0,38,0,100,0,1,2,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Moran - On Data Set 1 2 - Resume Waypoint"),
(@ID,0,3,0,40,0,100,0,18,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 18 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,16,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warmage Moran - On Waypoint 13 Reached - Pause Waypoint"),

(@ID*100+0,9,0,0,0,0,100,0,2000,2000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Moran - On Script - Cast 'Warmage Drake Fireball'"),
(@ID*100+0,9,1,0,0,0,100,0,6000,6000,0,0,0,11,45913,0,0,0,0,0,19,25724,0,0,0,0,0,0,0,"Warmage Moran - On Script - Cast 'Warmage Drake Fireball'");

DELETE FROM `waypoints` WHERE `entry` = 25727;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(25727,1,3432.6145,5915.464,147.46953,0,0,"Warmage Moran"),
(25727,2,3422.9866,5912.3257,149.60324,0,0,"Warmage Moran"),
(25727,3,3410.0647,5909.5728,152.02946,0,0,"Warmage Moran"),
(25727,4,3393.3308,5909.92,156.36287,0,0,"Warmage Moran"),
(25727,5,3367.2473,5916.6626,161.72395,0,0,"Warmage Moran"),
(25727,6,3340.2002,5924.8774,164.69623,0,0,"Warmage Moran"),
(25727,7,3313.7268,5936.971,164.72398,0,0,"Warmage Moran"),
(25727,8,3274.5618,5960.1597,163.11285,0,0,"Warmage Moran"),
(25727,9,3248.3792,5984.673,155.39067,0,0,"Warmage Moran"),
(25727,10,3222.7993,6007.353,146.02954,0,0,"Warmage Moran"),
(25727,11,3190.0996,6031.6606,134.91856,0,0,"Warmage Moran"),
(25727,12,3165.8325,6043.715,131.44637,0,0,"Warmage Moran"),
(25727,13,3145.7979,6060.3247,131.44637,0,0,"Warmage Moran"),
(25727,14,3138.7566,6079.489,131.44637,0,0,"Warmage Moran"),
(25727,15,3156.847,6108.7153,131.44637,0,0,"Warmage Moran"),
(25727,16,3183.6033,6109.2544,126.83527,0,0,"Warmage Moran"), --
(25727,17,3191.0652,6104.512,132.86238,0,0,"Warmage Moran"),
(25727,18,3195.6409,6102.6733,147.5568,0,13000,"Warmage Moran"), --
(25727,19,3178.9836,6067.5054,141.88358,0,0,"Warmage Moran"),
(25727,20,3203.0337,6040.6235,207.30002,0,0,"Warmage Moran"),
(25727,21,3222.4402,6012.923,253.57777,0,0,"Warmage Moran"),
(25727,22,3240.0286,5986.9424,289.54984,0,0,"Warmage Moran");

-- Ascended Mage Hunter SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25724 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2572400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25724,0,0,0,11,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Respawn - Set Reactstate Passive"),
(25724,0,1,0,1,0,100,1,1000,1000,0,0,0,11,45940,0,0,0,0,0,19,25594,10,0,0,0,0,0,0,"Ascended Mage Hunter - Out of Combat - Cast 'Evanor's Prison Chains' (No Repeat)"),
(25724,0,2,0,8,0,100,0,45913,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Spellhit 'Warmage Drake Fireball' - Set Active On"),
(25724,0,3,0,8,0,100,0,45913,0,0,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Spellhit 'Warmage Drake Fireball' - Interrupt Spell"),
(25724,0,4,0,8,0,100,0,45913,0,0,0,0,63,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Spellhit 'Warmage Drake Fireball' - Set Counter 1 1"),
(25724,0,5,0,77,0,100,0,1,1,0,0,0,11,42726,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 1 - Cast 'Cosmetic - Immolation (Whole Body)'"),
(25724,0,6,0,77,0,100,0,1,1,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 1 - Start Random Movement"),
(25724,0,7,0,77,0,100,0,1,2,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 2 - Cast 'Permanent Feign Death'"),
(25724,0,8,0,77,0,100,0,1,2,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 2 - Stop Random Movement"),
(25724,0,9,0,77,0,100,0,1,2,0,0,0,63,1,1,0,0,0,0,19,24771,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 2 - Set Counter 1 1 (Coldarra Invisman)"),
-- Guessed, otherwise we have to reset counter, remove all auras and force creature to cast channeling spell again
(25724,0,10,0,77,0,100,0,1,2,0,0,0,41,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ascended Mage Hunter - On Counter Set 1 2 - Delayed Despawn");

-- Coldarra Invisman SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24771 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2477100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24771,0,0,0,77,0,100,0,1,4,0,0,0,80,2477100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Invisman - On Counter Set 1 4 - Run Script"),

(2477100,9,0,0,0,0,100,0,3000,3000,0,0,0,9,0,0,0,0,0,0,20,187884,20,0,0,0,0,0,0,"Coldarra Invisman - On Script - Activate Closest Gameobject 'Evanor's Prison'"),
(2477100,9,1,0,0,0,100,0,5000,5000,0,0,0,11,46013,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Invisman - On Script - Cast 'Summon Lady Evanor'"),
(2477100,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,19,27888,250,0,0,0,0,0,0,"Coldarra Invisman - On Script - Despawn Instant (Warmage Archus)"),
(2477100,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,25727,250,0,0,0,0,0,0,"Coldarra Invisman - On Script - Despawn Instant (Warmage Moran)"),
(2477100,9,4,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,25732,250,0,0,0,0,0,0,"Coldarra Invisman - On Script - Despawn Instant (Warmage Preston)"),
(2477100,9,5,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,25733,250,0,0,0,0,0,0,"Coldarra Invisman - On Script - Despawn Instant (Warmage Austin)"),
(2477100,9,6,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Invisman - On Script - Despawn Instant");

-- Archmage Evanor SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25784 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2578400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25784,0,0,0,54,0,100,0,0,0,0,0,0,80,2578400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Evanor - On Just Summoned - Run Script"),

(2578400,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Say Line 0"),
(2578400,9,1,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Say Line 1"),
(2578400,9,2,0,0,0,100,0,0,0,0,0,0,11,46018,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Cast 'Teleport'"),
(2578400,9,3,0,0,0,100,0,8000,8000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Evanor - On Script - Despawn Instant");

-- Respawn time
-- Coldarra Invisman, sniffed (respawned before player was teleported)
UPDATE `creature` SET `spawntimesecs` = 15 WHERE `guid` = 114368 AND `id` = 24771;
-- Warmages, guessed, should be less than 40 sec (sniff)
UPDATE `creature` SET `spawntimesecs` = 15 WHERE `id` IN (27888,25727,25732,25733);
-- Ascended Mage Hunter, guessed
UPDATE `creature` SET `spawntimesecs` = 15 WHERE `id` = 25724;
