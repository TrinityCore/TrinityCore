--
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 256 WHERE `entry` = 2755;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2755 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 275500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2755,0,0,0,54,0,100,0,0,0,0,0,0,80,275500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - On Just Summoned - Run Script"),
(2755,0,1,0,0,0,100,0,5000,5000,10000,15000,0,11,4938,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - In Combat - Cast 'Myzrael Earthquake'"),
(2755,0,2,0,2,0,100,0,0,75,60000,90000,0,11,10388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - Between 0-75% Health - Cast 'Summon Prismatic Exile'"),
(2755,0,3,0,2,0,100,0,0,50,60000,90000,0,11,10388,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - Between 0-50% Health - Cast 'Summon Prismatic Exile'"),
(2755,0,4,0,2,0,100,0,0,25,60000,90000,0,11,4937,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - Between 0-25% Health - Cast 'Summon Prismatic Exiles'"),

(275500,9,0,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Myzrael - On Script - Say Line 0"),
(275500,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Myzrael - On Script - Set Orientation Owner"),
(275500,9,2,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Myzrael - On Script - Say Line 1"),
(275500,9,3,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Myzrael - On Script - Say Line 2"),
(275500,9,4,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Myzrael - On Script - Remove Flag Immune To Players"),
(275500,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Myzrael - On Script - Start Attack Owner");
