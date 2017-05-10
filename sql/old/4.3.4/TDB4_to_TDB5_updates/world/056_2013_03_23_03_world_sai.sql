UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE `entryorguid`=2289 AND `source_type`=1;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=1494;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1494;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(1494,0,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 'On Respawn - Say Line - Yell Text on Summon');
-- Add missing creature_text
DELETE FROM `creature_text` WHERE `entry`=1494 AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(1494,0,0, 'Mmmh...I SMELL FOOD!',14,0,100,0,0,0, 'Negolash Yell on Summon');
