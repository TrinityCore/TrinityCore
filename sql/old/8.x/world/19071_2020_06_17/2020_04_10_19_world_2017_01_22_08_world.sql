-- Reduce respawntime for landmine
UPDATE `gameobject` SET `spawntimesecs`=10 WHERE  `id`=191502;

-- add fake death emote for Savage Hill Scavengers
UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `unit_flags`=`unit_flags`|536870912|33554432|32770, `dynamicflags`=32 WHERE  `guid` IN (116957, 116956, 116958, 116959);
DELETE FROM `creature_addon` WHERE `guid` IN (116957, 116956, 116958, 116959);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(116957,0,0,7,1,0, '29266'),
(116956,0,0,7,1,0, '29266'),
(116958,0,0,7,1,0, '29266'),
(116959,0,0,7,1,0, '29266');

-- add textevent for Janks 
-- Janks SAI
SET @ENTRY := 29429;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Reset - Set Flag Standstate Sit Down"),
(@ENTRY,0,1,0,10,0,100,0,1,10,55000,55000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - Within 0-10 Range Out of Combat LoS - Run Script");

-- Actionlist SAI
SET @ENTRY := 2942900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Remove Flag Standstate Sit Down"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Say Line 3"),
(@ENTRY,9,6,0,0,0,100,0,3000,3000,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Set Flag Standstate Sit Down"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janks - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID`=29429;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(29429, 0, 0, 'Is it true?! Has someone finally come to get me out of this place?', 12, 0, 100, 0, 0, 0, 30198, 'Janks'),
(29429, 1, 0, 'No... no... that''s not it, is it? That heartless lout probably sent you after the tools, didn''t he?', 12, 0, 100, 0, 0, 0, 30199, 'Janks'),
(29429, 2, 0, 'Well... I guess I''ll just keep an eye on the turrets... or something.', 12, 0, 100, 0, 0, 0, 30200, 'Janks'),
(29429, 3, 0, '%s sighs.', 16, 0, 100, 0, 0, 0, 30201, 'Janks');
