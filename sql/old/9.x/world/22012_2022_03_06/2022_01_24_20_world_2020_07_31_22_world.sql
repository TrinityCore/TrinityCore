-- Make Honeybee follow player
-- https://www.youtube.com/watch?v=Jsz5NejMh3c
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 27866;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27866 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27866,0,0,0,54,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Honeybee - On Just Summoned - Start Follow Invoker");
