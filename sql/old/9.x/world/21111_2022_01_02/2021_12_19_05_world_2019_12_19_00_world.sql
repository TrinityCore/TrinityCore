-- 
UPDATE `creature_template` SET `speed_walk`=2.4, `speed_run`=0.857143  WHERE `entry` IN (20405,21534);
UPDATE `creature_template_addon` SET `auras`=""  WHERE `entry` IN (20405,21534);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20405) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20405, 0, 0, 0, 60, 0, 100, 0, 1000, 1000, 2000, 2000, 11, 35151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nether Charge - IN Update - CAST 'Nether Charge Pulse' (NO REPEAT)"),
(20405, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 75, 35150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nether Charge - IN Reset - Add aura Nether Charge Passive"),
(20405, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 37670, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nether Charge - IN Reset - Cast Nether Charge Timer"),
(20405, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nether Charge - IN Reset - React passive"),
(20405, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nether Charge - IN Reset - Random movement");
