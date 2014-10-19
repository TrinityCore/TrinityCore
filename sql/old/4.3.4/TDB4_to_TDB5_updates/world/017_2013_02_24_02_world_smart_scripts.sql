DELETE FROM `smart_scripts` WHERE `entryorguid`=29861 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`event_type`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(29861,0,54,80,2986100,2,1,'Stormforged Eradictor - Just summoned - Call timed actionlist 2986100');

DELETE FROM `smart_scripts` WHERE `entryorguid`=2986100 AND `source_type`=9;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUE
(2986100,9,0,10000,10000,12,29729,4,10000,8,6972.13,14.24,805.79,3.349,'Stormforged Eradictor - Timed actionlist - Summon Frostborn Axemaster');
