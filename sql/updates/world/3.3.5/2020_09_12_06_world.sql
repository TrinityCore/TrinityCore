-- Spell 34877 is used by player after 34878
UPDATE `quest_template_addon` SET `SourceSpellID` = 0 WHERE `ID` = 10277;

-- Andormu SAI
SET @ID := 20130;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,10277,0,0,0,0,11,34878,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Andormu - On Quest 'The Caverns of Time' Taken - Cast 'Custodian of Time'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 20130 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,20130,0,0,1,0,34877,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Custodian of Time'");

-- Custodian of Time SAI (Sniffed)
SET @ID := 20129;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+6 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Just Summoned - Run Script"),
(@ID,0,1,0,40,0,100,0,4,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 4 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,11,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 11 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,13,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 13 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,17,0,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 17 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,23,0,0,0,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 23 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,26,0,0,0,0,80,@ID*100+6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Waypoint 26 Reached - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,11,17321,0,0,0,0,0,11,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Cast 'Spirit Spawn-in'"),
(@ID*100+0,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,10000,10000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 1"),
(@ID*100+0,9,4,0,0,0,100,0,15000,15000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 2"),
(@ID*100+0,9,5,0,0,0,100,0,11000,11000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(@ID*100+0,9,6,0,0,0,100,0,2000,2000,0,0,0,53,0,20129,0,0,0,2,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+1,9,2,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 4"),
(@ID*100+1,9,3,0,0,0,100,0,10000,10000,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 5"),
(@ID*100+1,9,4,0,0,0,100,0,15000,15000,0,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 6"),
(@ID*100+1,9,5,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.46607,"Custodian of Time - On Script - Set Orientation"),
(@ID*100+1,9,6,0,0,0,100,0,1000,1000,0,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 7"),
(@ID*100+1,9,7,0,0,0,100,0,6000,6000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 25"),
(@ID*100+1,9,8,0,0,0,100,0,12000,12000,0,0,0,1,8,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 8"),
(@ID*100+1,9,9,0,0,0,100,0,7000,7000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+1,9,10,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 1"),
(@ID*100+1,9,11,0,0,0,100,0,14000,14000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(@ID*100+1,9,12,0,0,0,100,0,6000,6000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Resume Waypoint"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.58308,"Custodian of Time - On Script - Set Orientation"),
(@ID*100+2,9,2,0,0,0,100,0,2000,2000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 25"),
(@ID*100+2,9,3,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,0,1,9,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 9"),
(@ID*100+2,9,5,0,0,0,100,0,10000,10000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(@ID*100+2,9,6,0,0,0,100,0,6000,6000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Resume Waypoint"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.92699,"Custodian of Time - On Script - Set Orientation"),
(@ID*100+3,9,2,0,0,0,100,0,1000,1000,0,0,0,1,10,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 10"),
(@ID*100+3,9,3,0,0,0,100,0,3000,3000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Play Emote 1"),
(@ID*100+3,9,4,0,0,0,100,0,6000,6000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Resume Waypoint"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Pause Waypoint"),
(@ID*100+4,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+4,9,2,0,0,0,100,0,2000,2000,0,0,0,1,11,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 11"),
(@ID*100+4,9,3,0,0,0,100,0,20000,20000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(@ID*100+4,9,4,0,0,0,100,0,6000,6000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Resume Waypoint"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,54,120000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Pause Waypoint"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.19198,"Custodian of Time - On Script - Set Orientation"),
(@ID*100+5,9,2,0,0,0,100,0,1000,1000,0,0,0,1,12,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 12"),
(@ID*100+5,9,3,0,0,0,100,0,10000,10000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 3"),
(@ID*100+5,9,4,0,0,0,100,0,6000,6000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Resume Waypoint"),

(@ID*100+6,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Set Orientation Owner"),
(@ID*100+6,9,1,0,0,0,100,0,1000,1000,0,0,0,1,13,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Say Line 13"),
(@ID*100+6,9,2,0,0,0,100,0,0,0,0,0,0,11,34883,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Cast 'QID 10277'"),
(@ID*100+6,9,3,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Custodian of Time - On Script - Despawn Instant");

UPDATE `creature_text` SET `comment` = "Custodian of Time" WHERE `CreatureID` = @ID;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = @ID AND `GroupID` IN (0,1,2,4,5,6,7,9,11,13);
UPDATE `creature_text` SET `Emote` = 273 WHERE `CreatureID` = @ID AND `GroupID` = 3;
UPDATE `creature_text` SET `Emote` = 25 WHERE `CreatureID` = @ID AND `GroupID` IN (8,10,12);

DELETE FROM `script_waypoint` WHERE `entry` = 20129;
DELETE FROM `waypoints` WHERE `entry` = 20129;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(20129,1,-8383.195,-4244.2246,-206.63582,"Custodian of Time"),
(20129,2,-8401.535,-4229.1826,-206.77563,"Custodian of Time"),
(20129,3,-8431.324,-4205.2417,-209.29944,"Custodian of Time"),
(20129,4,-8446.195,-4199.217,-211.19778,"Custodian of Time"), --
(20129,5,-8458.105,-4211.28,-213.03964,"Custodian of Time"),
(20129,6,-8474.044,-4211.068,-214.48344,"Custodian of Time"),
(20129,7,-8496.167,-4213.949,-214.46599,"Custodian of Time"),
(20129,8,-8535.091,-4218.9146,-213.08104,"Custodian of Time"),
(20129,9,-8570.049,-4231.135,-211.34303,"Custodian of Time"),
(20129,10,-8598.164,-4247.1714,-210.84158,"Custodian of Time"),
(20129,11,-8627.352,-4268.6313,-210.40045,"Custodian of Time"), --
(20129,12,-8621.29,-4292.2915,-210.65274,"Custodian of Time"),
(20129,13,-8607.385,-4337.514,-211.93082,"Custodian of Time"), --
(20129,14,-8577.146,-4359.431,-214.54268,"Custodian of Time"),
(20129,15,-8561.278,-4380.342,-215.37544,"Custodian of Time"),
(20129,16,-8540.864,-4399.46,-216.24318,"Custodian of Time"),
(20129,17,-8523.853,-4407.744,-216.44739,"Custodian of Time"), --
(20129,18,-8488.358,-4429.706,-215.93779,"Custodian of Time"),
(20129,19,-8443.823,-4427.043,-213.41385,"Custodian of Time"),
(20129,20,-8409.723,-4412.882,-211.28308,"Custodian of Time"),
(20129,21,-8379.641,-4393.748,-208.27452,"Custodian of Time"),
(20129,22,-8359.075,-4369.809,-208.16708,"Custodian of Time"),
(20129,23,-8358.578,-4360.8413,-208.14444,"Custodian of Time"), --
(20129,24,-8363.002,-4342.101,-208.54948,"Custodian of Time"),
(20129,25,-8367.569,-4306.7544,-209.5187,"Custodian of Time"),
(20129,26,-8374.003,-4286.1333,-208.72986,"Custodian of Time"); --
