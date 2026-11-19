-- Civilian Recruit Scripts in Building
DELETE FROM `creature_addon` WHERE `guid`=117789;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(117789, 0, 0, 3, 0, 0, NULL);

-- Civilian Recruit SAI
SET @GUID := -117794;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25317;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,8000,8000,12000,12000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - Out of Combat - Play Emote 36"),
(@GUID,0,1,0,1,0,100,0,35000,40000,35000,40000,80,11779400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 11779400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,10,117790,25317,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 2"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 3");

-- Civilian Recruit SAI
SET @GUID := -117788;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=25317;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,8000,8000,12000,12000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - Out of Combat - Play Emote 36"),
(@GUID,0,1,0,1,0,100,0,35000,40000,35000,40000,80,11778800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 11778800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,6000,6000,0,0,1,2,6000,0,0,0,0,10,117789,25317,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 2"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,1,3,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Civilian Recruit - On Script - Say Line 3");


DELETE FROM `creature_text` WHERE `CreatureID`=25317 AND `GroupID` >=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- First text
(25317, 1, 0, 'This is harder than it looks.', 12, 7, 100, 0, 0, 0, 26488, 'Civilian Recruit'),
(25317, 1, 1, 'Did that seem okay?', 12, 7, 100, 0, 0, 0, 26487, 'Civilian Recruit'),
(25317, 1, 2, 'My arm is getting sore.', 12, 7, 100, 0, 0, 0, 26491, 'Civilian Recruit'),
(25317, 1, 3, 'Hmm....', 12, 7, 100, 0, 0, 0, 26492, 'Civilian Recruit'),
(25317, 1, 4, 'I think I\'m starting to get the hang of this.', 12, 7, 100, 0, 0, 0, 26490, 'Civilian Recruit'),
(25317, 1, 5, 'This isn\'t easy.', 12, 7, 100, 0, 0, 0, 26489, 'Civilian Recruit'),
-- reaction
(25317, 2, 0, 'You aren\'t going to let me sleep are you?', 12, 7, 100, 0, 0, 0, 26497, 'Civilian Recruit'),
(25317, 2, 1, 'Are you going to be doing this for much longer?', 12, 7, 100, 0, 0, 0, 26502, 'Civilian Recruit'),
(25317, 2, 2, 'Could you try to be a little quieter?', 12, 7, 100, 0, 0, 0, 26500, 'Civilian Recruit'),
-- reaction 2
(25317, 3, 0, 'I just don\'t want to let anyone down.', 12, 7, 100, 0, 0, 0, 26494, 'Civilian Recruit'),
(25317, 3, 1, 'I need to do something to keep myself busy.', 12, 7, 100, 0, 0, 0, 26495, 'Civilian Recruit'),
(25317, 3, 2, 'I\'m just nervous.  Sorry.', 12, 7, 100, 0, 0, 0, 26493, 'Civilian Recruit');
