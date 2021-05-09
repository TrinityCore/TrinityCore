-- Totem of Coo
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |512 WHERE `entry` = 17379;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17360,17379) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1737900,1737901) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17360,0,0,0,19,0,100,0,9539,0,0,0,0,11,30437,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Totem of Akida - On Quest 'Totem of Coo' Taken - Cast 'Stillpine Ancestor Akida TRIGGER'"),

(17379,0,0,0,54,0,100,0,0,0,0,0,0,80,1737900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Just Summoned - Run Script"),
(17379,0,1,0,40,0,100,0,12,0,0,0,0,80,1737901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Waypoint 12 Reached - Run Script"),

(1737900,9,0,0,0,0,100,0,0,0,0,0,0,3,0,16995,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Morph To Model 16995"),
(1737900,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Set Orientation Owner"),
(1737900,9,2,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Cast 'Elemental Spawn-in'"),
(1737900,9,3,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Say Line 0"),
(1737900,9,4,0,0,0,100,0,1000,1000,0,0,0,53,1,17379,0,0,0,2,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Start Waypoint"),

(1737901,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,17361,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Set Orientation Closest Creature 'Totem of Coo'"),
(1737901,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Say Line 1"),
(1737901,9,2,0,0,0,100,0,3000,3000,0,0,0,11,30428,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Cast 'Stillpine Ancestor Despawn DND'"),
(1737901,9,3,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Akida - On Script - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry` = 17379;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17379,1,-4154.224,-12514.748,45.355274,0,0,"Stillpine Ancestor Akida"),
(17379,2,-4123.5625,-12517.226,44.9127,0,0,"Stillpine Ancestor Akida"),
(17379,3,-4123.5625,-12517.226,44.9127,0,0,"Stillpine Ancestor Akida"),
(17379,4,-4091.8806,-12523.997,42.373543,0,0,"Stillpine Ancestor Akida"),
(17379,5,-4058.0386,-12538.569,43.960957,0,0,"Stillpine Ancestor Akida"),
(17379,6,-4026.534,-12568.403,45.822224,0,0,"Stillpine Ancestor Akida"),
(17379,7,-4000.155,-12598.554,54.197224,0,0,"Stillpine Ancestor Akida"),
(17379,8,-3977.5,-12627.216,63.144196,0,0,"Stillpine Ancestor Akida"),
(17379,9,-3952.2544,-12660.369,74.23783,0,0,"Stillpine Ancestor Akida"),
(17379,10,-3933.183,-12698.27,85.65151,0,0,"Stillpine Ancestor Akida"),
(17379,11,-3925.8433,-12718.808,89.94553,0,0,"Stillpine Ancestor Akida"),
(17379,12,-3915.914,-12743.413,98.567795,0,0,"Stillpine Ancestor Akida");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17360 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17360,0,0,1,0,30426,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Stillpine Ancestor Akida'");

-- Totem of Tikti
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |512, `flags_extra` = `flags_extra` |512 WHERE `entry` = 17391;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17361,17391) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1739100,1739101) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17361,0,0,0,19,0,100,0,9540,0,0,0,0,11,30442,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Totem of Coo - On Quest 'Totem of Tikti' Taken - Cast 'Stillpine Ancestor Coo TRIGGER'"),

(17391,0,0,0,54,0,100,0,0,0,0,0,0,80,1739100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Just Summoned - Run Script"),
(17391,0,1,0,40,0,100,0,3,0,0,0,0,80,1739101,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Waypoint 3 Reached - Run Script"),
(17391,0,2,0,40,0,100,0,6,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Waypoint 6 Reached - Despawn Instant"),

(1739100,9,0,0,0,0,100,0,0,0,0,0,0,3,0,16995,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Morph To Model 16995"),
(1739100,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Set Orientation Owner"),
(1739100,9,2,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Cast 'Elemental Spawn-in'"),
(1739100,9,3,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Say Line 0"),
(1739100,9,4,0,0,0,100,0,1000,1000,0,0,0,53,0,17391,0,0,0,2,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Start Waypoint"),

(1739101,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Pause Waypoint"),
(1739101,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Say Line 1"),
(1739101,9,2,0,0,0,100,0,4000,4000,0,0,0,11,30424,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Cast 'Ghost Walk'"),
(1739101,9,3,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Say Line 2"),
(1739101,9,4,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Say Line 3"),
(1739101,9,5,0,0,0,100,0,1000,1000,0,0,0,11,30473,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Cast 'Coo Transform Furbolg DND'"),
-- Morph template has 2 models, one is not correct
(1739101,9,6,0,0,0,100,0,0,0,0,0,0,3,0,17019,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Morph To Model 17019"),
(1739101,9,7,0,0,0,100,0,3000,3000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Disable Gravity"),
(1739101,9,8,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Set Run On"),
(1739101,9,9,0,0,0,100,0,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Coo - On Script - Resume Waypoint");

DELETE FROM `waypoints` WHERE `entry` = 17391;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17391,1,-3926.039,-12746.708,96.067795,0,0,"Stillpine Ancestor Coo"),
(17391,2,-3926.3262,-12753.709,98.442795,0,0,"Stillpine Ancestor Coo"),
(17391,3,-3924.2683,-12761.454,101.692795,0,0,"Stillpine Ancestor Coo"),
(17391,4,-3926.068,-12767.325,104.37994,0,0,"Stillpine Ancestor Coo"),
(17391,5,-3923.497,-12794.984,98.463234,0,0,"Stillpine Ancestor Coo"),
(17391,6,-3922.6868,-12832.404,89.240974,0,0,"Stillpine Ancestor Coo");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17361 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17361,0,0,1,0,30429,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Stillpine Ancestor Coo'");

-- Totem of Yor
UPDATE `creature_template` SET `speed_walk` = 0.66666798591, `speed_run` = 0.85714285714, `unit_flags` = `unit_flags` |32768 WHERE `entry` = 17392;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17362,17392) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1739200,1739201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17362,0,0,0,19,0,100,0,9541,0,0,0,0,11,30443,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Totem of Tikti - On Quest 'Totem of Yor' Taken - Cast 'Stillpine Ancestor Tikti TRIGGER'"),

(17392,0,0,0,54,0,100,0,0,0,0,0,0,80,1739200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Just Summoned - Run Script"),
(17392,0,1,0,40,0,100,0,1,0,0,0,0,80,1739201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Waypoint 1 Reached - Run Script"),
(17392,0,2,0,40,0,100,0,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Waypoint 3 Reached - Despawn Instant"),

(1739200,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Set Orientation Owner"),
(1739200,9,1,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Cast 'Elemental Spawn-in'"),
(1739200,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Say Line 0"),
(1739200,9,3,0,0,0,100,0,0,0,0,0,0,53,0,17392,0,0,0,2,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Start Waypoint"),
-- Below not really sniffed
(1739201,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Pause Waypoint"),
(1739201,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Say Line 1"),
(1739201,9,2,0,0,0,100,0,6000,6000,0,0,0,11,30430,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Cast 'Embrace of the Serpent'"),
(1739201,9,3,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Say Line 2"),
(1739201,9,4,0,0,0,100,0,1000,1000,0,0,0,11,30431,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Cast 'Tikti Transform DND'"),
(1739201,9,5,0,0,0,100,0,3000,3000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Resume Waypoint"),
(1739201,9,6,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Tikti - On Script - Set Run On");

DELETE FROM `waypoints` WHERE `entry` = 17392;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17392,1,-3885.6646,-13096.555,3.563835,0,0,"Stillpine Ancestor Tikti"),
(17392,2,-3913.36,-13055.2,-4.82595,0,0,"Stillpine Ancestor Tikti"),
(17392,3,-3951.4,-13033.9,-8.45508,0,0,"Stillpine Ancestor Tikti");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17362 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17362,0,0,1,0,30432,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Stillpine Ancestor Tikti'");

-- Totem of Vark
UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 17393;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17363,17393) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1739300,1739301,1739302,1739303) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17363,0,0,0,19,0,100,0,9542,0,0,0,0,11,30444,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Totem of Yor - On Quest 'Totem of Vark' Taken - Cast 'Stillpine Ancestor Yor TRIGGER'"),

(17393,0,0,0,54,0,100,0,0,0,0,0,0,80,1739300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Just Summoned - Run Script"),
(17393,0,1,0,40,0,100,0,1,0,0,0,0,80,1739301,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Waypoint 1 Reached - Run Script"),
(17393,0,2,0,40,0,100,0,2,0,0,0,0,80,1739302,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Waypoint 2 Reached - Run Script"),
(17393,0,3,0,40,0,100,0,64,0,0,0,0,80,1739303,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Waypoint 64 Reached - Run Script"),

(1739300,9,0,0,0,0,100,0,0,0,0,0,0,3,0,17002,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Morph To Model 17002"),
(1739300,9,1,0,0,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Elemental Spawn-in'"),
(1739300,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Set Orientation Owner"),
(1739300,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 0"),
(1739300,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,17393,0,0,0,2,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Start Waypoint"),
-- Below not really sniffed
(1739301,9,0,0,0,0,100,0,2000,2000,0,0,0,11,30446,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Yor Transform Furbolg DND'"),

(1739302,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Set Orientation Owner"),
(1739302,9,1,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 1"),
(1739302,9,2,0,0,0,100,0,3000,3000,0,0,0,11,30448,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest'"),
(1739302,9,3,0,0,0,100,0,0,0,0,0,0,11,30447,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Shadow of the Forest'"),
(1739302,9,4,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 2"),
(1739302,9,5,0,0,0,100,0,4000,4000,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Set Run On"),

(1739303,9,0,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Say Line 3"),
(1739303,9,1,0,0,0,100,0,2000,2000,0,0,0,11,30428,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Cast 'Stillpine Ancestor Despawn DND'"),
(1739303,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Stillpine Ancestor Yor - On Script - Despawn Instant");

DELETE FROM `waypoints` WHERE `entry` = 17393;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(17393,1,-4646.6274,-13015.363,-1.386728,0,2000,"Stillpine Ancestor Yor"),
(17393,2,-4679.14,-12985,0.5803,0,11000,"Stillpine Ancestor Yor"),
(17393,3,-4680.61,-12963.3,2.66436,0,0,"Stillpine Ancestor Yor"),
(17393,4,-4681.2,-12949.7,5.54,0,0,"Stillpine Ancestor Yor"),
(17393,5,-4682.73,-12929.5,3.47035,0,0,"Stillpine Ancestor Yor"),
(17393,6,-4667.73,-12909.8,1.50962,0,0,"Stillpine Ancestor Yor"),
(17393,7,-4647.96,-12887.9,2.97161,0,0,"Stillpine Ancestor Yor"),
(17393,8,-4639.09,-12877.2,4.9471,0,0,"Stillpine Ancestor Yor"),
(17393,9,-4630.71,-12855.1,4.28118,0,0,"Stillpine Ancestor Yor"),
(17393,10,-4620.17,-12829.9,6.06746,0,0,"Stillpine Ancestor Yor"),
(17393,11,-4612,-12814,7.12509,0,0,"Stillpine Ancestor Yor"),
(17393,12,-4601.96,-12795.7,3.27105,0,0,"Stillpine Ancestor Yor"),
(17393,13,-4588.53,-12774.2,7.44323,0,0,"Stillpine Ancestor Yor"),
(17393,14,-4575.77,-12760.8,6.10979,0,0,"Stillpine Ancestor Yor"),
(17393,15,-4563.73,-12744.2,9.99685,0,0,"Stillpine Ancestor Yor"),
(17393,16,-4554.96,-12729,12.2105,0,0,"Stillpine Ancestor Yor"),
(17393,17,-4547.41,-12712.1,9.81412,0,0,"Stillpine Ancestor Yor"),
(17393,18,-4538.2,-12689.2,12.5838,0,0,"Stillpine Ancestor Yor"),
(17393,19,-4533.22,-12668.1,16.8651,0,0,"Stillpine Ancestor Yor"),
(17393,20,-4532.96,-12656.8,15.2664,0,0,"Stillpine Ancestor Yor"),
(17393,21,-4532.78,-12637.9,16.5789,0,0,"Stillpine Ancestor Yor"),
(17393,22,-4533.02,-12619.1,12.0263,0,0,"Stillpine Ancestor Yor"),
(17393,23,-4532.77,-12592.5,14.642,0,0,"Stillpine Ancestor Yor"),
(17393,24,-4535.16,-12572.5,11.9603,0,0,"Stillpine Ancestor Yor"),
(17393,25,-4521.38,-12547.2,8.20642,0,0,"Stillpine Ancestor Yor"),
(17393,26,-4506.74,-12520.5,2.71515,0,0,"Stillpine Ancestor Yor"),
(17393,27,-4492.57,-12495.4,4.36968,0,0,"Stillpine Ancestor Yor"),
(17393,28,-4476.92,-12469.2,2.26036,0,0,"Stillpine Ancestor Yor"),
(17393,29,-4462.38,-12438.4,2.68436,0,0,"Stillpine Ancestor Yor"),
(17393,30,-4430.42,-12442,2.38524,0,0,"Stillpine Ancestor Yor"),
(17393,31,-4419.91,-12429.3,3.2091,0,0,"Stillpine Ancestor Yor"),
(17393,32,-4408.61,-12400.1,5.02559,0,0,"Stillpine Ancestor Yor"),
(17393,33,-4414.42,-12370.4,5.99229,0,0,"Stillpine Ancestor Yor"),
(17393,34,-4423.44,-12345,8.29463,0,0,"Stillpine Ancestor Yor"),
(17393,35,-4435.58,-12315.7,10.3162,0,0,"Stillpine Ancestor Yor"),
(17393,36,-4457.19,-12304.2,12.3064,0,0,"Stillpine Ancestor Yor"),
(17393,37,-4475.24,-12294,13.9122,0,0,"Stillpine Ancestor Yor"),
(17393,38,-4490.89,-12279.7,15.2792,0,0,"Stillpine Ancestor Yor"),
(17393,39,-4503.42,-12249.6,16.3871,0,0,"Stillpine Ancestor Yor"),
(17393,40,-4510.15,-12229.8,17.1362,0,0,"Stillpine Ancestor Yor"),
(17393,41,-4513.27,-12209.5,16.9777,0,0,"Stillpine Ancestor Yor"),
(17393,42,-4513.64,-12189.1,16.9593,0,0,"Stillpine Ancestor Yor"),
(17393,43,-4502.99,-12158,16.1291,0,0,"Stillpine Ancestor Yor"),
(17393,44,-4508.94,-12122.7,16.9898,0,0,"Stillpine Ancestor Yor"),
(17393,45,-4505.31,-12095.6,18.8873,0,0,"Stillpine Ancestor Yor"),
(17393,46,-4500.36,-12071.2,21.4168,0,0,"Stillpine Ancestor Yor"),
(17393,47,-4516.81,-12050.5,24.2492,0,0,"Stillpine Ancestor Yor"),
(17393,48,-4528.22,-12037.5,26.0347,0,0,"Stillpine Ancestor Yor"),
(17393,49,-4531.9,-12008.6,28.4037,0,0,"Stillpine Ancestor Yor"),
(17393,50,-4538.61,-11984.4,29.7635,0,0,"Stillpine Ancestor Yor"),
(17393,51,-4543.79,-11963.5,29.1954,0,0,"Stillpine Ancestor Yor"),
(17393,52,-4537.48,-11934.2,27.0094,0,0,"Stillpine Ancestor Yor"),
(17393,53,-4533.18,-11906.3,22.686,0,0,"Stillpine Ancestor Yor"),
(17393,54,-4504.71,-11879,17.5661,0,0,"Stillpine Ancestor Yor"),
(17393,55,-4500.36,-11845.7,15.0063,0,0,"Stillpine Ancestor Yor"),
(17393,56,-4510.63,-11816.8,13.8306,0,0,"Stillpine Ancestor Yor"),
(17393,57,-4531.7,-11786.6,15.5384,0,0,"Stillpine Ancestor Yor"),
(17393,58,-4555.94,-11756.9,17.6289,0,0,"Stillpine Ancestor Yor"),
(17393,59,-4546.7,-11735.9,19.533,0,0,"Stillpine Ancestor Yor"),
(17393,60,-4535.96,-11712.4,18.2368,0,0,"Stillpine Ancestor Yor"),
(17393,61,-4519.88,-11702.4,17.8815,0,0,"Stillpine Ancestor Yor"),
(17393,62,-4507,-11694.5,13.2184,0,0,"Stillpine Ancestor Yor"),
(17393,63,-4490.14,-11673,10.8723,0,0,"Stillpine Ancestor Yor"),
(17393,64,-4486.34,-11658,10.6353,0,0,"Stillpine Ancestor Yor");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 17363 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17363,0,0,1,0,30445,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Stillpine Ancestor Yor'");
