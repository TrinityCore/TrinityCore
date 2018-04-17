-- [Q] Galaen's Fate -- http://wotlk.openwow.com/quest=9579
-- Galaen's Corpse SAI
SET @ENTRY := 17508;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,19,0,100,0,9579,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Galaen's Corpse - On Quest 'Galaen's Fate' Taken - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,9579,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Galaen's Corpse - On Quest 'Galaen's Fate' Taken - Store Targetlist"),
(@ENTRY,0,2,0,17,0,100,0,17426,0,0,0,64,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Galaen's Corpse - On Summoned Unit - Store Targetlist");

-- Conditions for summon
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=17508;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,17508,0,0,29,0,17426,20,0,1,0,0,"","Galaen's Corpse - Do not summon Galaen if creature is in 20 yards range");

-- Actionlist SAI
SET @ENTRY := 1750800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,12,17426,1,15000,0,0,0,8,0,0,0,-2090.03,-11297.5,63.5025,3.56455,"Galaen's Corpse - On Script - Summon Creature 'Galaen'"),
(@ENTRY,9,1,0,0,0,100,0,100,100,0,0,100,1,0,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Send Target 1");

-- Actionlist SAI
SET @ENTRY := 1750800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,12,17426,1,15000,0,0,0,8,0,0,0,-2090.03,-11297.5,63.5025,3.56455,"Galaen's Corpse - On Script - Summon Creature 'Galaen'"),
(@ENTRY,9,1,0,0,0,100,0,100,100,0,0,100,1,0,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Send Target 1"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,45,1,1,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,0,3000,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,1,1,4000,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,1,2,4000,0,0,0,0,12,2,0,0,0,0,0,0,"Galaen's Corpse - On Script - Say Line 2");

-- Galaen SAI
SET @ENTRY := 17426;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Galaen - On Data Set 1 1 - Set Orientation Stored Payer");

DELETE FROM `creature_text` WHERE `CreatureID`=17426;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(17426, 0, 0, 'Morae... Is that you?', 12, 0, 100, 6, 0, 0, 14262, 'Galaen'),
(17426, 1, 0, 'No... you''re not Morae, but I sense that you have met. When you see her, tell her that I survived the crash, only to be done in by the infiltrators.', 12, 0, 100, 274, 0, 0, 14263, 'Galaen'),
(17426, 2, 0, 'Let her know... my last thought was of her...', 12, 0, 100, 1, 0, 0, 14264, 'Galaen');
