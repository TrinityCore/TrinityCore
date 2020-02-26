-- 
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (180763,180764,180870, 180871,180872, 180873);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (180763,180764,180870, 180871,180872, 180873) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(180763,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn"),
(180764,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn"),
(180870,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn"),
(180871,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn"),
(180872,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn"),
(180873,1,0,0,1,0,100,1,15000,60000,0,0,41,3000,10,0,0,0,0,1,0,0,0,0,0,0,0, "Firecrackers - Ooc - desspawn");
