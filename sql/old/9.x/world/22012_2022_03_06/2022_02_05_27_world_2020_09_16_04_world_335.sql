-- Some parts shown in https://www.youtube.com/watch?v=5xXlRJg9RXg
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 832 WHERE `entry` = 19666;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19666 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1966600 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19671 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1967100 AND 1967111 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19671,0,0,0,54,0,100,0,0,0,0,0,0,80,1967100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Just Summoned - Run Script"),

(19671,0,1,0,0,0,100,0,0,0,3000,5000,0,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - In Combat CMC - Cast 'Arcane Bolt'"),
(19671,0,2,0,0,0,100,0,15000,15000,20000,25000,0,11,14514,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - In Combat - Cast 'Blink'"),
(19671,0,3,0,0,0,100,0,4000,6000,15000,23000,0,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - In Combat - Cast 'Arcane Explosion'"),
(19671,0,4,0,23,0,100,0,33839,0,30000,30000,0,11,33839,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Missing Aura - Cast 'Vir'aani Concentration'"),

(19671,0,5,0,19,0,100,1,10218,0,0,0,0,80,1967103,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Quest 'Someone Else's Hard Work Pays Off' Taken - Run Script (No Repeat)"),
(19671,0,6,0,40,0,100,0,1,1967100,0,0,0,80,1967101,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 1 Reached - Run Script"),
(19671,0,7,0,40,0,100,0,3,1967100,0,0,0,80,1967102,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 3 Reached - Run Script"),
(19671,0,8,0,40,0,100,0,1,1967101,0,0,0,80,1967104,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 1 Reached - Run Script"),
(19671,0,9,0,40,0,100,0,8,1967101,0,0,0,80,1967105,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 8 Reached - Run Script"),
(19671,0,10,0,40,0,100,0,14,1967101,0,0,0,80,1967106,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 14 Reached - Run Script"),
(19671,0,11,0,40,0,100,0,18,1967101,0,0,0,80,1967107,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 18 Reached - Run Script"),
(19671,0,12,0,40,0,100,0,27,1967101,0,0,0,80,1967108,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 27 Reached - Run Script"),
(19671,0,13,0,40,0,100,0,30,1967101,0,0,0,80,1967109,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 30 Reached - Run Script"),
(19671,0,14,0,40,0,100,0,37,1967101,0,0,0,80,1967110,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 37 Reached - Run Script"),
(19671,0,15,0,40,0,100,0,2,1967102,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Waypoint 2 Reached - Despawn Instant"),

(19671,0,16,0,82,0,100,0,19666,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Summoned Unit 'Shadow Lord Xiraxis' Dies - Set Event Phase 1"),
(19671,0,17,0,1,1,100,0,500,500,500,500,0,80,1967111,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - Out of Combat - Run Script (Phase 1)"),
(19671,0,18,0,6,0,100,0,0,0,0,0,0,6,10218,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Death - Fail Quest 'Someone Else's Hard Work Pays Off'"),

(1967100,9,0,0,0,0,100,0,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set NPC Flags"),
(1967100,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 0"),
(1967100,9,2,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,21,100,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Orientation Closest Player"),
(1967100,9,3,0,0,0,100,0,1000,1000,0,0,0,1,1,0,1,0,0,0,21,100,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 1"),
(1967100,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,1967100,0,0,0,2,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Start Waypoint"),

(1967101,9,0,0,0,0,100,0,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967101,9,1,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 2"),
(1967101,9,2,0,0,0,100,0,1000,1000,0,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 234"),
(1967101,9,3,0,0,0,100,0,4000,4000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 0"),
-- Transports Consortium Laborer & Consortium Engineer, all summons are handled by this object, first summon after 5 secs
-- GO Rotation: X: 0 Y: 0 Z: 0.09584522 W: 0.99539626
(1967101,9,4,0,0,0,100,0,0,0,0,0,0,50,183850,7200,0,0,0,0,8,0,0,0,0,-373.15,-73.353,-0.95876,0.19198,"Cryo-Engineer Sha'heen - On Script - Summon Gameobject 'Consortium Transporter'"),

(1967102,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.26179,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967102,9,1,0,0,0,100,0,5000,5000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 3"),
(1967102,9,2,0,0,0,100,0,3000,3000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967102,9,3,0,0,0,100,0,2000,2000,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set NPC Flags"),

(1967103,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Store Targetlist"),
(1967103,9,1,0,0,0,100,0,0,0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Faction 495"),
(1967103,9,2,0,0,0,100,0,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set NPC Flags"),
(1967103,9,3,0,0,0,100,0,1000,1000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 4"),
(1967103,9,4,0,0,0,100,0,4000,4000,0,0,0,53,0,1967101,0,0,0,2,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Start Waypoint"),

(1967104,9,0,0,0,0,100,0,0,0,0,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967104,9,1,0,0,0,100,0,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 233"),
(1967104,9,2,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Orientation Stored Target 1"),
(1967104,9,3,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 0"),
(1967104,9,4,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 5"),

(1967105,9,0,0,0,0,100,0,0,0,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967105,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.26179,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967105,9,2,0,0,0,100,0,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 233"),
(1967105,9,3,0,0,0,100,0,0,0,0,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 6"),
(1967105,9,4,0,0,0,100,0,0,0,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Summon Group 0"),
(1967105,9,5,0,0,0,100,0,5000,5000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 0"),
(1967105,9,6,0,0,0,100,0,0,0,0,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 7"),

(1967106,9,0,0,0,0,100,0,0,0,0,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967106,9,1,0,0,0,100,0,0,0,0,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 8"),
(1967106,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,5.04400,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967106,9,3,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.66322,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967106,9,4,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 9"),

(1967107,9,0,0,0,0,100,0,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967107,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.13962,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967107,9,2,0,0,0,100,0,1000,1000,0,0,0,1,10,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 10"),
(1967107,9,3,0,0,0,100,0,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 233"),
(1967107,9,4,0,0,0,100,0,1000,1000,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Summon Group 1"),
(1967107,9,5,0,0,0,100,0,5000,5000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 0"),

(1967108,9,0,0,0,0,100,0,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967108,9,1,0,0,0,100,0,1000,1000,0,0,0,1,11,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 11"),
(1967108,9,2,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,3,0,0,0,100,0,2000,2000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,4,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,5,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,6,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,7,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,8,0,0,0,100,0,2000,2000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,9,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),
(1967108,9,10,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 1"),

(1967109,9,0,0,0,0,100,0,0,0,0,0,0,54,48000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Pause Waypoint"),
(1967109,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,6.09119,"Cryo-Engineer Sha'heen - On Script - Set Orientation"),
(1967109,9,2,0,0,0,100,0,2000,2000,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 233"),
(1967109,9,3,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Orientation Stored Target 1"),
(1967109,9,4,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Emote State 0"),
(1967109,9,5,0,0,0,100,0,0,0,0,0,0,1,12,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 12"),
(1967109,9,6,0,0,0,100,0,20000,20000,0,0,0,1,13,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 13"),
(1967109,9,7,0,0,0,100,0,10000,10000,0,0,0,1,14,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 14"),

(1967110,9,0,0,0,0,100,0,0,0,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Summon Group 2"),

(1967111,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Set Event Phase 0"),
(1967111,9,1,0,0,0,100,0,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Play Emote 15"),
(1967111,9,2,0,0,0,100,0,4000,4000,0,0,0,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 16"),
(1967111,9,3,0,0,0,100,0,0,0,0,0,0,15,10218,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Quest Credit 'Someone Else's Hard Work Pays Off'"),
(1967111,9,4,0,0,0,100,0,6000,6000,0,0,0,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Say Line 17"),
(1967111,9,5,0,0,0,100,0,2000,2000,0,0,0,53,1,1967102,0,0,0,2,1,0,0,0,0,0,0,0,0,"Cryo-Engineer Sha'heen - On Script - Start Waypoint"),

(19666,0,0,1,54,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Just Summoned - Say Line 0"),
(19666,0,1,0,61,0,100,0,0,0,0,0,0,53,1,19666,0,0,0,2,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Link - Start Waypoint"),
(19666,0,2,0,40,0,100,0,3,0,0,0,0,80,1966600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Waypoint 3 Reached - Run Script"),

(1966600,9,0,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Say Line 1"),
(1966600,9,1,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Play Emote 1"),
(1966600,9,2,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Play Emote 1"),
(1966600,9,3,0,0,0,100,0,2000,2000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Play Emote 1"),
(1966600,9,4,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Play Emote 1"),
(1966600,9,5,0,0,0,100,0,1000,1000,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Play Emote 1"),
(1966600,9,6,0,0,0,100,0,0,0,0,0,0,1,15,0,0,0,0,0,19,19671,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Say Line 15 (Cryo-Engineer Sha'heen)"),
(1966600,9,7,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Say Line 2"),
(1966600,9,8,0,0,0,100,0,2000,2000,0,0,0,2,1678,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Set Faction 1678"),
(1966600,9,9,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(1966600,9,10,0,0,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadow Lord Xiraxis - On Script - Set In Combat With Zone");

UPDATE `creature_text` SET `Emote` = 0 WHERE `CreatureID` = 19671 AND `GroupID` IN (6,7);
DELETE FROM `creature_text` WHERE `CreatureID` = 19671 AND `GroupID` BETWEEN 10 AND 17;
DELETE FROM `creature_text` WHERE `CreatureID` = 19666;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19671,10,0,"There can't be too many more of these collectors. Just keep me safe as I do my job.",12,0,100,0,0,0,17255,0,"Cryo-Engineer Sha'heen"),
(19671,11,0,"What do we have here? I thought you said the area was secure? This is now the third attack? If we make it out of here, I will definitely be deducting this from your reward. Now don't just stand there, destroy them so I can get to that collector.",12,0,100,1,0,0,17256,0,"Cryo-Engineer Sha'heen"),
(19671,12,0,"We're close to the exit. I'll let you rest for about thirty seconds, but then we're out of here.",12,0,100,1,0,0,17258,0,"Cryo-Engineer Sha'heen"),
(19671,13,0,"Are you ready to go?",12,0,100,0,0,0,17260,0,"Cryo-Engineer Sha'heen"),
(19671,14,0,"Ok break time is OVER. Let's go!",12,0,100,1,0,0,17261,0,"Cryo-Engineer Sha'heen"),
(19671,15,0,"Oh really? And what might that be?",12,0,100,1,0,0,17263,0,"Cryo-Engineer Sha'heen"),
(19671,16,0,"He was right, you know. I'll have to take that tag-line for my own... It's not like he'll have a use for it anymore!",12,0,100,1,0,0,17264,0,"Cryo-Engineer Sha'heen"),
(19671,17,0,"Thanks and good luck!",12,0,100,1,0,0,17265,0,"Cryo-Engineer Sha'heen"),
(19666,0,0,"Bravo! Bravo! Good show... I couldn't convince you to work for me, could I? No, I suppose the needless slaughter of my employees might negatively impact your employment application.",14,0,100,0,0,0,17241,0,"Shadow Lord Xiraxis"),
(19666,1,0,"Your plan was a good one, Sha'heen, and you would have gotten away with it if not for one thing...",12,0,100,1,0,0,17243,0,"Shadow Lord Xiraxis"),
(19666,2,0,"Never underestimate the other ethereal's greed!",12,0,100,15,0,0,17244,0,"Shadow Lord Xiraxis");

DELETE FROM `waypoints` WHERE `entry` IN (1967100,1967101,1967102);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1967100,1,-354.44296,-65.607796,-0.9741728,"Cryo-Engineer Sha'heen"),
(1967100,2,-357.67813,-68.876816,-0.96592534,"Cryo-Engineer Sha'heen"),
(1967100,3,-364.53583,-72.458565,-0.958762,"Cryo-Engineer Sha'heen"),

(1967101,1,-370.5689,-73.03973,0.70142555,"Cryo-Engineer Sha'heen"), --
(1967101,2,-363.58023,-72.44846,-0.9587624,"Cryo-Engineer Sha'heen"),
(1967101,3,-371.8158,-86.79798,-0.958762,"Cryo-Engineer Sha'heen"),
(1967101,4,-372.80673,-115.39024,-0.9587386,"Cryo-Engineer Sha'heen"),
(1967101,5,-373.52664,-149.39684,-0.9787918,"Cryo-Engineer Sha'heen"),
(1967101,6,-382.36737,-163.1939,-0.94938123,"Cryo-Engineer Sha'heen"),
(1967101,7,-378.77283,-164.44315,-0.121638335,"Cryo-Engineer Sha'heen"),
(1967101,8,-375.34207,-164.19107,0.7157794,"Cryo-Engineer Sha'heen"), --
(1967101,9,-381.80365,-167.04987,-0.95876294,"Cryo-Engineer Sha'heen"),
(1967101,10,-374.27042,-195.67,-0.9876157,"Cryo-Engineer Sha'heen"),
(1967101,11,-371.05222,-221.11539,-0.95754796,"Cryo-Engineer Sha'heen"),
(1967101,12,-357.35254,-224.11176,-0.95915943,"Cryo-Engineer Sha'heen"),
(1967101,13,-327.2074,-223.1011,-0.958185,"Cryo-Engineer Sha'heen"),
(1967101,14,-317.37302,-220.93457,-0.95304704,"Cryo-Engineer Sha'heen"), --
(1967101,15,-302.13904,-201.61092,-0.90185827,"Cryo-Engineer Sha'heen"),
(1967101,16,-291.98376,-190.27065,-0.9321695,"Cryo-Engineer Sha'heen"),
(1967101,17,-272.20444,-165.11417,-1.9620669,"Cryo-Engineer Sha'heen"),
(1967101,18,-260.87378,-158.34235,-1.2030103,"Cryo-Engineer Sha'heen"), --
(1967101,19,-246.70212,-160.23555,-0.95347977,"Cryo-Engineer Sha'heen"),
(1967101,20,-238.46686,-174.35815,-0.953746,"Cryo-Engineer Sha'heen"),
(1967101,21,-237.85226,-188.02318,-0.9510807,"Cryo-Engineer Sha'heen"),
(1967101,22,-218.73232,-207.17525,0.047778234,"Cryo-Engineer Sha'heen"),
(1967101,23,-183.58006,-223.29243,-0.9551997,"Cryo-Engineer Sha'heen"),
(1967101,24,-147.253,-222.20169,-0.71591794,"Cryo-Engineer Sha'heen"),
(1967101,25,-114.524895,-221.92604,0.40133548,"Cryo-Engineer Sha'heen"),
(1967101,26,-89.60782,-222.85197,-0.51873076,"Cryo-Engineer Sha'heen"),
(1967101,27,-67.58874,-223.65367,-0.405379,"Cryo-Engineer Sha'heen"), --
(1967101,28,-56.864796,-223.16153,0.026393188,"Cryo-Engineer Sha'heen"),
(1967101,29,-20.567297,-224.03325,0.5167194,"Cryo-Engineer Sha'heen"),
(1967101,30,-12.585793,-222.50667,1.786049,"Cryo-Engineer Sha'heen"), --
(1967101,31,-29.403599,-223.26056,0.01665334,"Cryo-Engineer Sha'heen"),
(1967101,32,-53.08645,-219.65143,0.21370609,"Cryo-Engineer Sha'heen"),
(1967101,33,-64.90977,-210.44235,-0.29250205,"Cryo-Engineer Sha'heen"),
(1967101,34,-66.850426,-179.13803,-1.3071523,"Cryo-Engineer Sha'heen"),
(1967101,35,-67.13032,-133.7884,-1.0349374,"Cryo-Engineer Sha'heen"),
(1967101,36,-67.16659,-112.94309,-0.7426757,"Cryo-Engineer Sha'heen"),
(1967101,37,-67.0159,-87.2571,-1.2767712,"Cryo-Engineer Sha'heen"), --
-- Incomplete
(1967102,1,-67.6084,-38.390553,-0.9524499,"Cryo-Engineer Sha'heen"),
(1967102,2,-63.464592,-14.181664,-0.9479865,"Cryo-Engineer Sha'heen");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 19671 AND `summonerType` = 0;
DELETE FROM `creature_summon_groups` WHERE `summonerId` = 183850 AND `summonerType` = 1;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(19671,0,0,18315,-375.89005,-130.7981,-0.95874935,4.69930,6,300000,"Cryo-Engineer Sha'heen - Group 0 - Ethereal Theurgist"), -- 0xF130478B0000B7B0
(19671,0,0,18315,-374.61023,-197.6735,-0.9794866,1.65319,6,300000,"Cryo-Engineer Sha'heen - Group 0 - Ethereal Theurgist"), -- 0xF130478B0000B7B1
(19671,0,0,18312,-370.30167,-131.25328,-0.95874065,4.57273,6,300000,"Cryo-Engineer Sha'heen - Group 0 - Ethereal Spellbinder"), -- 0xF13047880000B7B2
(19671,0,0,18312,-369.85764,-197.36095,-0.9686134,1.86010,6,300000,"Cryo-Engineer Sha'heen - Group 0 - Ethereal Spellbinder"), -- 0xF13047880000B7B3
(19671,0,1,18313,-284.01434,-188.3314,-0.35524964,0.92949,6,300000,"Cryo-Engineer Sha'heen - Group 1 - Ethereal Sorcerer"), -- 0xF13047890000B829
(19671,0,1,18313,-288.83862,-178.64357,-0.55568826,0.65805,6,300000,"Cryo-Engineer Sha'heen - Group 1 - Ethereal Sorcerer"), -- 0xF13047890000B82A
(19671,0,1,18313,-224.9607,-172.39752,-1.0441809,2.72163,6,300000,"Cryo-Engineer Sha'heen - Group 1 - Ethereal Sorcerer"), -- 0xF13047890000B82B
(19671,0,1,18311,-237.70796,-186.74799,-0.95137125,1.65800,6,300000,"Cryo-Engineer Sha'heen - Group 1 - Ethereal Crypt Raider"), -- 0xF13047870000B82C
(19671,0,2,19666,-36.3667,1.31717,-0.954333,3.2856,6,300000,"Cryo-Engineer Sha'heen - Group 2 - Shadow Lord Xiraxis"),
(183850,1,0,19672,-360.1015,-67.558876,-0.87543267,0.20943,8,0,"Consortium Transporter - Group 0 - Consortium Laborer"),
(183850,1,0,19673,-375.72964,-88.8795,-0.8754307,3.38593,8,0,"Consortium Transporter - Group 0 - Consortium Engineer"),
(183850,1,0,19672,-386.84702,-72.835556,-0.8754347,2.63544,8,0,"Consortium Transporter - Group 0 - Consortium Laborer"),
(183850,1,0,19672,-370.8748,-82.775795,-0.8754287,0.08726,8,0,"Consortium Transporter - Group 0 - Consortium Laborer"),
(183850,1,0,19672,-374.69434,-63.504593,-0.87543166,0.57595,8,0,"Consortium Transporter - Group 0 - Consortium Laborer"),
(183850,1,0,19673,-358.8426,-74.0751,-0.87266266,0.68067,8,0,"Consortium Transporter - Group 0 - Consortium Engineer"),
(183850,1,0,19672,-386.89282,-60.84314,-0.8754397,3.36848,8,0,"Consortium Transporter - Group 0 - Consortium Laborer");

/*
Gameobject Consortium Transporter summons Consortium Laborer & Consortium Engineer since there's no way
it's done in Cryo-Engineer Sha'heen's script. Cannot be implemented properly currently in SAI because timers, count and 
NPC entries are random. Or maybe can be done by spawn groups. The thing is timers are pretty confusing, in most cases intervals
between summons are 10 or 5 or 15 secs but despawn time is random
Currently only one and first group will be summoned. Positions and other stuff below.
Seems like they should be summoned over and over again without any limit

Entry - Pos - Guid - Time when despawn spell was started, creature always despawns after 3 sec after spell was started (1 sec to cast and 2 to despawn)
00:54:48.000 Number: 59627
72 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD80000B742 00:55:20.000
73 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD90000B743 00:55:07.000
72 -386.84702 Y: -72.835556 Z: -0.8754347 2.635447263717651367 0xF1304CD80000B744 00:55:15.000
72 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD80000B745 00:55:10.000
72 -374.69434 Y: -63.504593 Z: -0.87543166 0.575958669185638427 0xF1304CD80000B746 00:55:17.000
73 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD90000B747 00:55:12.000
72 -386.89282 Y: -60.84314 Z: -0.8754397 3.368485450744628906 0xF1304CD80000B748 00:55:14.000
00:55:14.000 Number: 60604
72 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD80000B75D 00:55:41.000
00:55:19.000 Number: 60747
72 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD80000B766 00:55:36.000
73 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD90000B767 00:55:30.000
73 -386.84702 Y: -72.835556 Z: -0.8754347 2.63544726371765136 0xF1304CD90000B768 00:55:52.000
73 -386.89282 Y: -60.84314 Z: -0.8754397 3.368485450744628906 0xF1304CD90000B769 00:55:52.000
00:55:24.000 Number: 60915
73 -374.69434 Y: -63.504593 Z: -0.87543166 0.575958669185638427 0xF1304CD90000B76D 00:55:56.000
72 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD80000B76E 00:55:52.000
00:55:34.000 Number: 61063
73 -359.37628 Y: -74.941086 Z: -0.94886255 4.160092353820800781 0xF1304CD90000B777 00:55:49.000
00:55:44.000 Number: 61221
72 -370.8759 Y: -82.74834 Z: -0.9587624 1.610428810119628906 0xF1304CD80000B783 00:55:58.000
00:55:49.000 Number: 61349
73 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD90000B785 00:56:03.000
00:55:54.000 Number: 61472
73 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD90000B78A 00:56:24.000
00:55:59.000 Number: 61601
72 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD80000B78F despawn time only - 00:56:26.000
73 -386.84702 Y: -72.835556 Z: -0.8754347 2.635447263717651367 0xF1304CD90000B790 00:56:21.000
73 -374.69434 Y: -63.504593 Z: -0.87543166 0.575958669185638427 0xF1304CD90000B791 00:56:28.000
73 -386.89282 Y: -60.84314 Z: -0.8754397 3.368485450744628906 0xF1304CD90000B792 despawn time only - 00:56:30.000
00:56:04.000 Number: 61773
73 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD90000B79A 00:56:20.000
00:56:14.000 Number: 62026
72 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD80000B7A6 00:56:37.000
00:56:25.000 Number: 62369
73 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD90000B7B7 00:56:55.000
72 -386.84702 Y: -72.835556 Z: -0.8754347 2.635447263717651367 0xF1304CD80000B7B8 despawn time only - 00:56:51.000
00:56:30.000 Number: 62726
72 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD80000B7BB
00:56:45.000 Number: 63843
73 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD90000B7CA 00:57:10.000
00:57:00.000 Number: 64286
73 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD90000B7D8
-- Maybe player leaved instance
01:05:41.000 Number: 81506
73 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD90000BA97 01:06:10.000
01:05:56.000 Number: 82065
72 -374.69434 Y: -63.504593 Z: -0.87543166 0.575958669185638427 0xF1304CD80000BAA8 01:06:22.000
01:06:01.000 Number: 82297
73 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD90000BAAC 01:06:25.000
72 -375.72964 Y: -88.8795 Z: -0.8754307 3.385938644409179687 0xF1304CD80000BAAD 01:06:32.000
72 -370.8748 Y: -82.775795 Z: -0.8754287 0.087266460061073303 0xF1304CD80000BAAE 01:06:19.000
72 -386.89282 Y: -60.84314 Z: -0.8754397 3.368485450744628906 0xF1304CD80000BAAF 01:06:24.000
73 -386.84702 Y: -72.835556 Z: -0.8754347 2.635447263717651367 0xF1304CD90000BAB0 01:06:19.000
01:06:17.000 Number: 82971
72 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD80000BAC3 01:06:38.000
01:06:27.000 Number: 83649
72 -374.69434 Y: -63.504593 Z: -0.87543166 0.575958669185638427 0xF1304CD80000BACB despawn time only - 01:06:41.000
01:06:32.000 Number: 83925
72 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD80000BACF 01:06:46.000
01:06:42.000 Number: 84873
72 -360.1015 Y: -67.558876 Z: -0.87543267 0.209439516067504882 0xF1304CD80000BAD9 despawn time only - 01:06:54.000
01:06:52.000 Number: 85556
72 -358.8426 Y: -74.0751 Z: -0.87266266 0.680678427219390869 0xF1304CD80000BAE0
*/

-- Consortium Transporter is not spawned by default
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` = 183850);
DELETE FROM `gameobject` WHERE `id` = 183850;

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 183850;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 183850 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(183850,1,0,0,60,0,100,1,5000,5000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Transporter - On Update - Summon Group 0 (No Repeat)");

-- Consortium Laborer & Engineer
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19672,19673) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1967200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19672,0,0,0,54,0,100,0,0,0,0,0,0,80,1967200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Just Summoned - Run Script"),

(1967200,9,0,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Script - Cast 'Simple Teleport'"),
(1967200,9,1,0,0,0,100,0,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Script - Start Random Movement"),
(1967200,9,2,0,0,0,100,0,17000,32000,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Script - Stop Random Movement"),
(1967200,9,3,0,0,0,100,0,0,0,0,0,0,11,7791,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Script - Cast 'Teleport'"),
(1967200,9,4,0,0,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Laborer - On Script - Despawn (3000)"),

(19673,0,0,0,54,0,100,0,0,0,0,0,0,80,1967200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Engineer - On Just Summoned - Run Script"),
(19673,0,1,0,38,0,100,1,1,1,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-3076.02,4942.94,-101.048,0.060653,"Consortium Engineer - On Data Set 1 1 - Move to Position"),
(19673,0,2,0,34,0,100,1,8,1,0,0,0,87,1967300,1967301,0,0,0,0,1,0,0,0,0,0,0,0,0,"Consortium Engineer - On Reached Point 1 - Run Random Script");

-- Only creatures outside instance should do emote, also fix sheath
UPDATE `creature_template_addon` SET `bytes2` = 257, `emote` = 0 WHERE `entry` IN (19672,19673);
UPDATE `creature_addon` SET `bytes2` = 257 WHERE `guid` IN (84498,84507);
DELETE FROM `creature_addon` WHERE `guid` IN (84499,84500,84501,84502,84504);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`emote`) VALUES
(84499,257,233),
(84500,257,233),
(84501,257,233),
(84502,257,233),
(84504,257,233);

-- Nexus Terror was removed from summon list and attack start not needed anymore
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19307 AND `source_type` = 0 AND `id` = 4;

-- Ethereal Sorcerer too should attack
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18313 AND `source_type` = 0 AND `id` = 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18313,0,5,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,19671,0,0,0,0,0,0,0,"Ethereal Spellbinder - On Just Summoned - Start Attacking Closest Creature 'Cryo-Engineer Sha'heen'");
