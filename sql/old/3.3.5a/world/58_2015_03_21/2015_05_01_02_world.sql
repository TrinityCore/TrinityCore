DELETE FROM `creature` WHERE `id`=3939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3939;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3939 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3265 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3265, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 6479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Razormane Hunter- On Reset - Cast to summon Razormane Wolf'),
(3939, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 6000, 9000, 11, 17255, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Razormane Wolf - IC - Cast Bite'),
(3939, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 22000, 25000, 11, 24604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Razormane Wolf - IC - Furious Howl');
