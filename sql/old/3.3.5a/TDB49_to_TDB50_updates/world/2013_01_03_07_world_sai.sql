DELETE FROM `gameobject_scripts` WHERE `id` IN (12609,26185,30534);
DELETE FROM `smart_scripts` WHERE `entryorguid`=177673 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17767300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(177673,1,0,0,70,0,100,0,2,0,0,0,80,17767300,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Serpent Statue - On activate - Start Script'),
(17767300,9,0,0,1,0,100,0,2000,2000,0,0,12,12369,1,300000,0,1,0,8,0,0,0,251.381,2962.47,2.76527,0.860446, 'Serpent Statue - After 2s - Summon Lord Kragaru');
