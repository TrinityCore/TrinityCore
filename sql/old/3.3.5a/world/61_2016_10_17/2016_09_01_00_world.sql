-- Fix Cabal Abjurist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=21660 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_type`,`event_chance`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`target_param1`,`comment`) VALUES
(21660,0,0,0,100,0,0,2000,3000,11,34447,2,0,"Cabal Abjurist - In Combat - Cast 'Arcane Missiles' at Victim"),
(21660,0,1,0,100,5000,9000,13000,18000,11,11831,25,10,"Cabal Abjurist - In Combat - Cast 'Frost Nova' if enemy within 10yd");
