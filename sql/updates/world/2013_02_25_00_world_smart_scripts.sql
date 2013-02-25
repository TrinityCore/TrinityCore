DELETE FROM `smart_scripts` WHERE `entryorguid`=29861 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(29861,0,0,54,0,0,0,0,80,2986100,2,1,'Stormforged Eradictor - Just summoned - Call timed actionlist 2986100'),
(29861,0,1,0,3000,7000,14000,18000,11,56352,0,2,'Stormforged Eradictor - Cast Storm Punch'),
(29861,0,2,0,9000,12000,13000,18000,11,15588,0,0,'Stormforged Eradictor - Cast Thunderclap');
