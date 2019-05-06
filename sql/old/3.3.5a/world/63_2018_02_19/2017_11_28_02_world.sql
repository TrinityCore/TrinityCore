-- Naias
UPDATE `event_scripts` SET `x`= -12132.446289, `y`=964.982422, `z`= 5.194236, `o`= 5.130559 WHERE `id`=10554;
SET @ENTRY := 17207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,37054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Naias - IC - cast Water Bolt'),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,10000,14000,11,34828,0,0,0,0,0,2,0,0,0,0,0,0,0,'Naias - IC -cast Water Shield'),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Naias - just summoned - say text');

DELETE FROM `creature_text` WHERE `CreatureID`=17207;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17207, 0, 0, 'Who challenges Naias? Puny $r, you are little better than those mindless trolls I have played against each other like so many pieces on a game board!', 12, 0, 100, 0, 0, 0, 13560, 0, 'Naias');
