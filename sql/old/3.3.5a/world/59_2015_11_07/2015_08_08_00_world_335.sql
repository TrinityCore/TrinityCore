-- 
UPDATE `event_scripts` SET `x`=38.4345, `y`=156.9295, `z`=83.545, `o`=1.407458 WHERE `id`=8438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (14500);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14500) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1450000, 1450001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14500,0,0,0,54,0,100,0,0,0,0,0,80,1450000,2,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On just summoned  - Action list"),
(1450000,9,0,0,0,0,100,0,0,0,0,0,64,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Store target"),
(1450000,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Say text 1"),
(1450000,9,2,0,0,0,100,0,2000,2000,0,0,53,0,14500,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - Actionlist  - start wp"),
(14500,0,1,0,40,0,100,0,2,14500,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp2 reached  - Pause wp"),
(14500,0,2,0,40,0,100,0,2,14500,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp2 reached  - Say text 2"),
(14500,0,3,0,40,0,100,0,7,14500,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp7 reached  - Pause wp"),
(14500,0,4,0,40,0,100,0,8,14500,0,0,1,2,4000,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp7 reached  - Say text 3"),
(14500,0,5,0,40,0,100,0,11,14500,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp11 reached  - Pause wp"),
(14500,0,6,0,40,0,100,0,12,14500,0,0,80,1450001,2,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - On wp12 reached  - Action list"),
(1450001,9,0,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Say text 4"),
(1450001,9,1,0,0,0,100,0,0,0,0,0,33,14500,0,0,0,0,0,12,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Quest credit"),
(1450001,9,2,0,0,0,100,0,3000,3000,0,0,11,41232,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Cast teleport"),
(1450001,9,3,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"J'eevee - Actionlist  - Despawn");

DELETE FROM `waypoints` WHERE `entry`=14500;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(14500,1, 38.784, 160.639, 83.545, "J'eevee"), 
(14500,2, 36.804, 160.705, 83.545, "J'eevee"),
(14500,3, 39.287, 160.044, 83.545, "J'eevee"), 
(14500,4, 41.666, 154.591, 83.545, "J'eevee"), 
(14500,5, 45.255, 155.014, 83.545, "J'eevee"), 
(14500,6, 44.930, 161.186, 83.545, "J'eevee"), 
(14500,7, 44.347, 161.120, 83.545, "J'eevee"),
(14500,8, 46.758, 157.877, 83.545, "J'eevee"),
(14500,9, 44.640, 154.405, 83.545, "J'eevee"), 
(14500,10, 33.498, 156.046, 83.545, "J'eevee"), 
(14500,11, 28.269, 160.792, 83.545, "J'eevee"),
(14500,12, 33.294, 160.895, 83.545, "J'eevee");

DELETE FROM `creature_text` WHERE `entry` IN (14500);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(14500,0,0,"Ah, here we are! Well let's get to work, shall we...?",12,0,100,0,0,0, 'J''eevee', 9769),
(14500,1,0,"Oh, right! Over here now...",12,0,100,0,0,0, 'J''eevee', 9770),
(14500,2,0,"And now... the final step!",12,0,100,0,0,0, 'J''eevee', 9771),
(14500,3,0,"I'm finished. The parchment is made. Now, return to Gorzeeki...",12,0,100,0,0,0, 'J''eevee', 9742);
