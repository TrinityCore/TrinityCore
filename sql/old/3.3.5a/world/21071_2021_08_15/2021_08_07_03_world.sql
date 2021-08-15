--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23282 AND `source_type` = 0 AND `id` BETWEEN 8 AND 11;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23282,0,8,9,40,0,100,0,1,23282,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidia - On Reached WP1 - Set Unit Flags"),
(23282,0,9,10,61,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidia - On Reached WP1 - Set Home Position"),
(23282,0,10,0,61,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Obsidia - On Reached WP1 - Set Aggresive");
