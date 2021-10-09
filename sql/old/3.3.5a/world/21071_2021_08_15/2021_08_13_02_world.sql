--
UPDATE `creature_template` SET `minlevel` = 60, `maxlevel` = 60, `speed_walk` = 1, `unit_flags` = 33554432, `AIName` = 'SmartAI' WHERE `entry` = 14366;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 14366 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14366,0,0,0,63,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warpwood Spores - On Just Created - Delayed Despawn"),
-- This blocks combat completely while in sniff creature can enter in combat and the only flags it has are Root and Unselectable
-- But of course it can't move or rotate or attack in melee, means we don't have 'something'
-- From Classic with love
(14366,0,1,0,63,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warpwood Spores - On Just Created - Set Reactstate Passive"),
(14366,0,2,0,63,0,100,0,0,0,0,0,0,11,22802,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warpwood Spores - On Just Created - Cast 'Choking Spores'");
