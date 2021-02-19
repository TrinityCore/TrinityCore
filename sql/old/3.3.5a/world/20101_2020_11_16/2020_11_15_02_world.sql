--
UPDATE `event_scripts` SET `x` = 8206.527, `y` = -6348.002, `z` = 64.6009, `o` = 0.922533512115478515, `Comment` = "Event (Spell 'Bury Pendant' (33980)) - On Event - Summon Creature 'Whitebark's Spirit'" WHERE `id` = 12530;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 19456;

DELETE FROM `waypoints` WHERE `entry` = 19456;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(19456,1,8208.947,-6344.807,64.63468,0,0,"Whitebark's Spirit"),
(19456,2,8211.638,-6334.2466,64.63468,0.31258,0,"Whitebark's Spirit"); -- guessed orientation

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19456 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19456,0,0,1,63,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Just Created - Set Invincibility HP 1"),
(19456,0,1,2,61,0,100,0,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Set Health Regeneration Off"),
(19456,0,2,3,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Say Line 0"),
(19456,0,3,0,61,0,100,0,0,0,0,0,0,53,0,19456,0,0,0,2,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Start Waypoint"),

(19456,0,4,0,0,0,100,0,18000,23000,15000,25000,0,11,11442,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Whitebark's Spirit - In Combat - Cast 'Withered Touch'"),
(19456,0,5,0,0,0,100,0,15000,20000,25000,30000,0,11,31287,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Whitebark's Spirit - In Combat - Cast 'Entangling Roots'"),

(19456,0,6,7,2,0,100,1,0,15,0,0,0,46,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - Between 0-15% Health - Attack Stop (No Repeat)"),
(19456,0,7,8,61,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Say Line 1"),
(19456,0,8,9,61,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Set Home Position"),
(19456,0,9,10,61,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Set Faction 35"),
(19456,0,10,11,61,0,100,0,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Despawn"),
(19456,0,11,0,61,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Whitebark's Spirit - On Link - Evade");
