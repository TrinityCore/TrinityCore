-- Guessed timers, too short sniff
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 29631;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 29631);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29631 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2963100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29631,0,0,0,1,0,100,0,30000,30000,120000,120000,0,80,2963100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Awilo Lon'gomba - Out of Combat - Run Script"),

(2963100,9,0,0,0,0,100,0,0,0,0,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Awilo Lon'gomba - On Script - Set Emote State 234"),
(2963100,9,1,0,0,0,100,0,60000,60000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Awilo Lon'gomba - On Script - Set Emote State 0");
