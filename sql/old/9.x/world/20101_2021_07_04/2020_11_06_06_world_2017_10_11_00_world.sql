-- D.E.H.T.A. Enforcer
DELETE FROM `creature_text` WHERE `CreatureID`= 25808 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25808,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'D.E.H.T.A. Enforcer'),
(25808,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'D.E.H.T.A. Enforcer'),
(25808,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'D.E.H.T.A. Enforcer');

-- Archdruid Lathorius <D.E.H.T.A.>
DELETE FROM `creature_text` WHERE `CreatureID`= 25809 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25809,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'Archdruid Lathorius <D.E.H.T.A.>'),
(25809,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'Archdruid Lathorius <D.E.H.T.A.>'),
(25809,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'Archdruid Lathorius <D.E.H.T.A.>');

-- Hierophant Cenius <D.E.H.T.A.>
DELETE FROM `creature_text` WHERE `CreatureID`= 25810 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25810,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'Hierophant Cenius <D.E.H.T.A.>'),
(25810,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'Hierophant Cenius <D.E.H.T.A.>'),
(25810,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'Hierophant Cenius <D.E.H.T.A.>');

-- Zaza <D.E.H.T.A.>
DELETE FROM `creature_text` WHERE `CreatureID`=25811 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25811,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'Zaza <D.E.H.T.A.>'),
(25811,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'Zaza <D.E.H.T.A.>'),
(25811,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'Zaza <D.E.H.T.A.>');

-- Killinger the Den Watcher <D.E.H.T.A.>
DELETE FROM `creature_text` WHERE `CreatureID`= 25812 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25812,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'Killinger the Den Watcher <D.E.H.T.A.>'),
(25812,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'Killinger the Den Watcher <D.E.H.T.A.>'),
(25812,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'Killinger the Den Watcher <D.E.H.T.A.>');

-- D.E.H.T.A. Enforcer (BIRD)
DELETE FROM `creature_text` WHERE `CreatureID`= 25819 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25819,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'D.E.H.T.A. Enforcer'),
(25819,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'D.E.H.T.A. Enforcer'),
(25819,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'D.E.H.T.A. Enforcer');

-- Hierophant Liandra <D.E.H.T.A.>
DELETE FROM `creature_text` WHERE `CreatureID`= 25838 AND `ID`>=0;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25838,0,0,' Do you think us fools! You\'re covered in animal blood!',12,0,100,5,4000,0,25052,0,'Hierophant Liandra <D.E.H.T.A.>'),
(25838,0,1,' BUTCHER! DIE!',12,0,100,5,4000,0,25053,0,'Hierophant Liandra <D.E.H.T.A.>'),
(25838,0,2,' Calf killer! Murderer! You will pay for this!',12,0,100,5,4000,0,25054,0,'Hierophant Liandra <D.E.H.T.A.>');

-- D.E.H.T.A. Enforcer SAI
SET @ENTRY := 25808;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"D.E.H.T.A. Enforcer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,10,0,100,0,1,20,0,0,49,2,0,0,0,0,0,25,20,1,0,0,0,0,0,"D.E.H.T.A. Enforcer - Within 1-20 Range Out of Combat LoS - Start Attacking");

-- D.E.H.T.A. Enforcer SAI
SET @ENTRY := 25819;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"D.E.H.T.A. Enforcer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,10,0,100,0,1,20,0,0,49,0,0,0,0,0,0,25,20,1,0,0,0,0,0,"D.E.H.T.A. Enforcer - Within 1-20 Range Out of Combat LoS - Start Attacking");

-- Arch Druid Lathorius SAI
SET @ENTRY := 25809;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Lathorius - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Lathorius - On Aggro - Remove Npc Flags Gossip & Questgiver"),
(@ENTRY,0,2,0,10,0,100,0,1,20,0,0,49,0,0,0,0,0,0,25,20,1,0,0,0,0,0,"Arch Druid Lathorius - Within 1-20 Range Out of Combat LoS - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid Lathorius - On Reset - Set Npc Flags Gossip & Questgiver");

-- Zaza SAI
SET @ENTRY := 25811;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zaza - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zaza - On Aggro - Remove Npc Flag Questgiver"),
(@ENTRY,0,2,0,10,0,100,0,1,20,0,0,49,0,0,0,0,0,0,25,20,1,0,0,0,0,0,"Zaza - Within 1-20 Range Out of Combat LoS - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zaza - On Reset - Set Npc Flag Questgiver");

-- Hierophant Cenius SAI
SET @ENTRY := 25810;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Cenius - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Cenius - On Aggro - Remove Npc Flag Questgiver"),
(@ENTRY,0,2,0,10,0,100,0,1,20,0,0,49,0,0,0,0,0,0,25,20,1,0,0,0,0,0,"Hierophant Cenius - Within 1-20 Range Out of Combat LoS - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Cenius - On Reset - Set Npc Flag Questgiver");

-- Killinger the Den Watcher SAI
SET @ENTRY := 25812;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Killinger the Den Watcher - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Killinger the Den Watcher - On Aggro - Remove Npc Flag Questgiver"),
(@ENTRY,0,2,0,10,0,100,0,1,20,0,0,49,0,0,0,0,0,0,25,20,1,0,0,0,0,0,"Killinger the Den Watcher - Within 1-20 Range Out of Combat LoS - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Killinger the Den Watcher - On Reset - Set Npc Flag Questgiver");

-- Hierophant Liandra SAI
SET @ENTRY := 25838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Liandra - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Liandra - On Aggro - Remove Npc Flag Questgiver"),
(@ENTRY,0,2,0,10,0,100,0,1,25,0,0,49,0,0,0,0,0,0,25,25,1,0,0,0,0,0,"Hierophant Liandra - Within 1-25 Range Out of Combat LoS - Start Attacking"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Liandra - On Reset - Set Npc Flag Questgiver"),
(@ENTRY,0,4,0,4,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Liandra - On Aggro - Remove Flag Standstate Sit Down"),
(@ENTRY,0,5,0,25,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hierophant Liandra - On Reset - Set Flag Standstate Sit Down");

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (29894, 25819);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=25819;

SET @NPC:=132984;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,1329840,0,0,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=1329840;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(1329840,1,3197.389, 5262.509, 59.1744, 5.665670,0,0,0,100,0),
(1329840,2,3205.473, 5261.450, 59.1744, 0.418089,0,0,0,100,0),
(1329840,3,3213.649, 5266.860, 59.1744, 0.630147,0,0,0,100,0),
(1329840,4,3220.222, 5276.440, 59.1744, 1.021275,0,0,0,100,0),
(1329840,5,3219.638, 5285.621, 59.1744, 1.939406,0,0,0,100,0),
(1329840,6,3211.313, 5295.542, 59.1744, 2.873245,0,0,0,100,0),
(1329840,7,3199.114, 5292.031, 59.1744, 3.573035,0,0,0,100,0),
(1329840,8,3193.253, 5282.330, 59.1744, 4.762128,0,0,0,100,0),
(1329840,9,3195.002, 5273.082, 59.1744, 4.700867,0,0,0,100,0);
