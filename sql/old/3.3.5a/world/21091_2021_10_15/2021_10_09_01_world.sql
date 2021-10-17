--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2491600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2491600,9,0,0,0,0,100,0,0,0,0,0,0,11,44943,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flare - Action list - cast"),
(2491600,9,1,0,0,0,100,0,0,0,0,0,0,3,24958,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flare - Action list - morph"),
(2491600,9,2,0,0,0,100,0,0,0,0,0,0,28,44880,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flare - Action list - Remove aura"),
(2491600,9,3,0,0,0,100,0,0,0,0,0,0,11,46196,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flare - Action list - Add aura"),
(2491600,9,4,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flare - Action list - Hackily stop follow movement"),
(2491600,9,5,0,0,0,100,0,1000,1000,0,0,0,53,1,24916,0,0,500,3,1,0,0,0,0,0,0,0,0,"Flare - Action list - Start way point");

UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 24937;
