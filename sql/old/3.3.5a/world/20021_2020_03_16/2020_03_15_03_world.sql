-- Pet Script Misc
-- Tyrael's Hilt (39656)
DELETE FROM `creature_text` WHERE `creatureid`=29089;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(29089, 0, 0, '%s falls asleep.', 16, 0, 100, 0, 0, 0, 6542, 'Mini-Tyrael'),
(29089, 1, 0, '%s becomes enraged.', 16, 0, 100, 0, 0, 0, 7798, 'Mini-Tyrael');
DELETE FROM `creature_template_addon` WHERE `entry`=29089;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(29089,0,0,0,0,0, '69205'); -- 79328 for cata
-- Mini Tyrael SAI
SET @ENTRY := 29089;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,34,60000,60000,0,11,54398,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - Received Emote 34 - Cast Tyrael Dance"),
(@ENTRY,0,1,0,8,0,100,0,69204,0,10000,10000,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+02,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Spellhit 'Sleepy Pet' - Run Random Script");
-- Actionlist SAI
SET @ENTRY := 2908900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,15000,15000,0,0,28,69204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Remove Aura 'Sleepy Pet'");
-- Actionlist SAI
SET @ENTRY := 2908901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,15000,15000,0,0,28,69204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Remove Aura 'Sleepy Pet'"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Say Line 1");
-- Actionlist SAI
SET @ENTRY := 2908902;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,28,69204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mini Tyrael - On Script - Remove Aura 'Sleepy Pet'");
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (29089) AND `SourceGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 29089, 0, 0, 33, 0, 1, 2, 0, 0, 0, 0, "", "SAI triggers only if player in raid/party'");
