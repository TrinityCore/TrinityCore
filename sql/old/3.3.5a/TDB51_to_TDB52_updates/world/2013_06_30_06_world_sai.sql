DELETE FROM `smart_scripts` WHERE `entryorguid` IN(24688,24689,24690);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(24688,0,0,0,2,0,100,6,0,20,29000,39000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wretched Skulker - On Less than 20% HP - Cast Drink Fel Infusion'),
(24688,0,1,0,0,0,100,6,6200,14000,5000,12000,11,44533,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wretched Skulker - In Combat - Cast Wretched Stab'),
(24689,0,0,0,2,0,100,6,0,20,23000,33000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wretched Bruiser - On Less than 20% HP - Cast Drink Fel Infusion'),
(24689,0,1,0,0,0,100,6,3800,3800,6000,11000,11,44534,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wretched Bruiser - In Combat - Cast Wretched Strike'),
(24690,0,0,0,2,0,100,6,0,20,29000,39000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wretched Husk - On Less than 20% HP - Cast Drink Fel Infusion'),
(24690,0,1,0,0,0,50,6,5000,5000,7000,17000,11,44503,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wretched Husk - In Combat - Cast Wretched Fireball'),
(24690,0,2,0,0,0,50,6,6500,6500,14000,24000,11,44504,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wretched Husk - In Combat - Cast Wretched Frostbolt');
