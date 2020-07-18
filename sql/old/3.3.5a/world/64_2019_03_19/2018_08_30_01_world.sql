-- 
UPDATE `smart_scripts` SET `event_param1`=180000, `event_param2`=180000, `event_param3`=180000, `event_param4`=180000 WHERE `entryorguid` IN (-111996, -112005) AND `source_type`=0 AND `id`=0;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(38505);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-112002,-111993,38505,38493) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3850500,38505*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-112002, 0, 0, 0, 60, 0, 100, 0, 60000, 90000, 60000, 90000, 80, 38505*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - On Update - Run Script'),
(38505*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38505, 4, 120000, 0, 0, 0, 8, 0, 0, 0, 5898.320, 2041.114, 636.0415, 1.841691, 'Knight of the Ebon Blade - On Script - Summon Creature Knight of the Ebon Blade'),
(-111993, 0, 0, 0, 60, 0, 100, 0, 60000, 90000, 60000, 90000, 80, 38505*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Argent Cruasder - On Update - Run Script'),
(38505*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38493, 4, 120000, 0, 0, 0, 8, 0, 0, 0, 5837.231, 2179.012, 636.0412, 6.169237, 'Argent Cruasder - On Script - Summon Creature Argent Cruasder'),
(38505, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 38505, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - On Just summoned - start watpoint'),
(38505, 0, 1, 0, 40, 0, 100, 0, 9, 38505, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Knight of the Ebon Blade - On waypoint reached - despawn'),
(38493, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 38493, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Argent Cruasder - On Just summoned - start watpoint'),
(38493, 0, 1, 0, 40, 0, 100, 0, 9, 38493, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Argent Cruasder - On waypoint reached - despawn');

DELETE FROM `waypoints` WHERE `entry` IN (38493,38505);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(38493,1,5856.899, 2179.507, 636.041,""),
(38493,2,5867.398, 2157.619, 636.041,""),
(38493,3,5873.770, 2144.504, 636.041,""),
(38493,4,5871.876, 2124.536, 636.041,""),
(38493,5,5865.335, 2107.692, 635.977,""),
(38493,6,5854.102, 2101.100, 636.034,""),
(38493,7,5826.581, 2088.601, 636.064,""),
(38493,8,5810.641, 2081.362, 636.064,""),
(38493,9,5782.596, 2068.108, 636.064,""),
(38505,1,5894.719, 2067.567, 636.041,""),
(38505,2,5886.676, 2082.452, 636.041,""),
(38505,3,5876.980, 2088.505, 636.041,""),
(38505,4,5868.985, 2102.083, 636.041,""),
(38505,5,5868.985, 2102.083, 636.041,""),
(38505,6,5853.833, 2101.389, 636.034,""),
(38505,7,5830.794, 2090.629, 636.063,""),
(38505,8,5812.584, 2082.479, 636.063,""),
(38505,9,5782.596, 2068.108, 636.064,"");
