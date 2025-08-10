--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30154,29525) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3015400,2952500) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30154,0,0,0,62,0,100,0,9874,0,0,0,0,80,3015400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Gossip Option 0 Selected - Run Script"),
(30154,0,1,0,21,0,100,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Reached Home - Reset Faction"),
(30154,0,2,0,6,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,10,103591,29525,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Death - Set Data 1 1 (Zeev Fizzlespark)"),

(3015400,9,0,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Script - Close Gossip"),
(3015400,9,1,0,0,0,100,0,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Script - Set Faction 14"),
(3015400,9,2,0,0,0,100,0,0,0,0,0,0,11,55716,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Script - Cast 'Victorious Challenger Dummy'"),
(3015400,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Script - Say Line 0"),
(3015400,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Agnetta Tyrsdottar - On Script - Start Attack Invoker"),

(29525,0,0,0,38,0,100,0,1,1,0,0,0,80,2952500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zeev Fizzlespark - On Data Set 1 1 - Run Script"),
(29525,0,1,0,40,0,100,0,4,29525,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zeev Fizzlespark - On Waypoint 4 Reached - Despawn"),

(2952500,9,0,0,0,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zeev Fizzlespark - On Script - Play Emote 4"),
(2952500,9,1,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zeev Fizzlespark - On Script - Say Line 0"),
(2952500,9,2,0,0,0,100,0,2000,2000,0,0,0,53,1,29525,0,0,0,3,1,0,0,0,0,0,0,0,0,"Zeev Fizzlespark - On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry` = 29525;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(29525,1,6890.022,-1585.2145,820.9559,"Zeev Fizzlespark"),
(29525,2,6879.4707,-1576.7057,821.9559,"Zeev Fizzlespark"),
(29525,3,6859.151,-1561.3475,821.39526,"Zeev Fizzlespark"),
(29525,4,6837.5625,-1544.6599,819.27026,"Zeev Fizzlespark");

UPDATE `creature` SET `spawntimesecs` = 65 WHERE `id` IN (29525,30154);
