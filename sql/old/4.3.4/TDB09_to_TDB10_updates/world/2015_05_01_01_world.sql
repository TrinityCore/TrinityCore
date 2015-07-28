UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=16348;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16348 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16345 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16345, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 28904, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Shadowpine Catlord - On Reset - Cast to summon Ghostclaw Lynx'),
(16348, 0, 0, 0, 0, 0, 100, 0, 3000, 7000, 8000, 12000, 11, 16828, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Ghostclaw Lynx - IC - Cast Claw'),
(16348, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 150000, 11, 59881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Ghostclaw Lynx - IC - Cast Rake');
