-- Jol Intro fix for quest "Redemption" (9598) 
-- Jol Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`=17509;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17509,0,0,"Read the tome of divinity I have given you, $n.  When you have learned from the book, speak with me again.",12,7,100,1,0,0,19811,0,"Jol");

-- Jol SAI Script
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17509;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17509 AND `event_type` IN (19,61);
DELETE FROM `smart_scripts` WHERE `entryorguid`=1750900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17509,0,0,1,19,0,100,0,9598,0,0,0,0,83,19,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jol - On Quest 'Redemption' Accepted - Remove Npc Flag Questgiver+Trainer+Gossip"),
(17509,0,1,0,61,0,100,0,0,0,0,0,0,80,1750900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jol - On Link - Run Script"),
(1750900,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Jol - On Script - Set Orientation Invoker"),
(1750900,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Jol - On Script - Say Line 0"),
(1750900,9,2,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jol - On Script - Set Orientation Home Position"),
(1750900,9,3,0,0,0,100,0,1000,1000,0,0,0,82,19,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jol - On Script - Add Npc Flag Questgiver+Trainer+Gossip");
