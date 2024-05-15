-- Captured Sunhawk Agent missing dialogue after interrogation
-- Script
UPDATE `smart_scripts` SET `link`=2 WHERE `entryorguid`=17824 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17824 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17824,0,2,3,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captured Sunhawk Agent - On Link - Set Orientation Invoker"),
(17824,0,3,0,61,0,100,0,9141,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Captured Sunhawk Agent - On Link - Say Text 0');

-- Creature text
DELETE FROM `creature_text` WHERE `CreatureID`=17824; 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17824,0,0,"Treacherous whelp! Sironas will destroy you and your people!",12,7,100,5,0,0,14637,0,"Captured Sunhawk Agent");
