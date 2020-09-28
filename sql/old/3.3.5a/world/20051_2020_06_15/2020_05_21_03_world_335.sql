-- Shrine of the Eagle & Shrine of the Falcon & Shrine of the Hawk SAI
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` IN (185547,185551,185553);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (185547,185551,185553) AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(185551,1,0,1,64,0,100,0,1,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shrine of the Hawk - On Gossip Hello - Store Targetlist"),
(185551,1,1,2,61,0,100,0,0,0,0,0,0,12,22992,4,60000,0,0,0,8,0,0,0,0,-4362.77,4626.06,-39.2711,0.86199,"Shrine of the Hawk - On Link - Summon Creature 'Guardian of the Hawk'"),
(185551,1,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,22992,50,0,0,0,0,0,0,"Shrine of the Hawk - On Link - Send Target 1 (Guardian of the Hawk)"),
(185547,1,0,1,64,0,100,0,1,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shrine of the Eagle - On Gossip Hello - Store Targetlist"),
(185547,1,1,2,61,0,100,0,0,0,0,0,0,12,22993,4,60000,0,0,0,8,0,0,0,0,-2623.6,4573.66,138.827,1.64381,"Shrine of the Eagle - On Link - Summon Creature 'Guardian of the Eagle'"),
(185547,1,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,22993,50,0,0,0,0,0,0,"Shrine of the Eagle - On Link - Send Target 1 (Guardian of the Eagle)"),
(185553,1,0,1,64,0,100,0,1,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shrine of the Falcon - On Gossip Hello - Store Targetlist"),
(185553,1,1,2,61,0,100,0,0,0,0,0,0,12,22994,4,60000,0,0,0,8,0,0,0,0,-3166.13,3809.05,59.7824,1.84486,"Shrine of the Falcon - On Gossip Hello - Summon Creature 'Guardian of the Falcon'"),
(185553,1,2,0,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,22994,50,0,0,0,0,0,0,"Shrine of the Falcon - On Link - Send Target 1 (Guardian of the Falcon)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 1 AND `SourceEntry` IN (185547,185551,185553) AND `SourceId` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,185551,1,0,29,1,22992,50,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Guardian of the Hawk' is not near"),
(22,1,185547,1,0,29,1,22993,50,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Guardian of the Eagle' is not near"),
(22,1,185553,1,0,29,1,22994,50,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature 'Guardian of the Falcon' is not near");

-- Guardian of the Hawk SAI
SET @ID := 22992;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Just Created - Run Script"),
(@ID,0,1,0,0,0,100,0,16000,20000,17000,23000,0,11,40358,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Cast 'Death Hammer'"),
(@ID,0,2,0,0,0,100,0,8000,12000,18000,25000,0,11,40412,32,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Cast 'Curse of Blood'"),
-- Not sure how to use this
(@ID,0,3,0,0,0,100,0,10000,15000,25000,35000,0,11,40413,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Hawk - In Combat - Cast 'Throw'"),
-- Unique for each because original timers may be not the same for all of them
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Flag Not Attackable"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Emote State 27"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,4500,4500,0,0,0,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Remove Flag Not Attackable"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Reactstate Agressive"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Set Emote State 0"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Hawk - On Script - Start Attacking Stored Target");

-- Guardian of the Eagle SAI
SET @ID := 22993;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Just Created - Run Script"),
(@ID,0,1,0,0,0,100,0,15000,15000,7000,7000,0,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 'Wrath'"),
(@ID,0,2,0,0,0,100,0,18000,18000,7000,7000,0,11,40339,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 'Force Target to Summon Raven Add'"),
(@ID,0,3,0,0,0,100,0,24000,24000,30000,30000,0,11,40344,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Eagle - In Combat - Cast 'Starfire'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Flag Not Attackable"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Emote State 27"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,4500,4500,0,0,0,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Remove Flag Not Attackable"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Reactstate Agressive"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Set Emote State 0"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Eagle - On Script - Start Attacking Stored Target");

-- Guardian of the Falcon SAI
SET @ID := 22994;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,63,0,100,0,0,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Just Created - Run Script"),
(@ID,0,1,0,0,0,100,0,5000,10000,9000,15000,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Shadow Bolt'"),
(@ID,0,2,0,0,0,100,0,12000,15000,15000,15000,0,11,32712,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Shadow Nova'"),
(@ID,0,3,0,0,0,100,0,9000,15000,6000,17000,0,11,40366,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Mark of Anzu'"),
(@ID,0,4,0,0,0,100,0,15000,15000,20000,30000,0,11,40367,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Twisting Blast'"),
(@ID,0,5,0,0,0,100,0,20000,21000,15000,25000,0,11,40368,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Nether Vortex'"),
(@ID,0,6,0,0,0,100,0,15000,20000,25000,35000,0,11,40400,0,0,0,0,0,6,0,0,0,0,0,0,0,0,"Guardian of the Falcon - In Combat - Cast 'Hex'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,18,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Flag Not Attackable"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,17,27,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Emote State 27"),
(@ID*100+0,9,3,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Say Line 1"),
(@ID*100+0,9,5,0,0,0,100,0,4500,4500,0,0,0,19,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Remove Flag Not Attackable"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Reactstate Agressive"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Set Emote State 0"),
(@ID*100+0,9,8,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Guardian of the Falcon - On Script - Start Attacking Stored Target");
