-- Anchorite Elbadon
-- His waypoint script is pretty tricky, looks like he can start any of two scripts randomly after reaching any(not sure) point.
-- Spell cast event occurs less often. All scripts are delayed by 1 or 2.5 or 2 secs and delay doesn't depends on point id.
-- He just always starts script before he reaches next waypoint.
-- The way how timers works is another story since there may be more than one timer 20 - 20 or 40 - 40 or 60 - 60,
-- Blizz sometimes likes to use multiple random timers, that's not something completely new. However I'm not entirely
-- sure if this is how it works in this case. Even with 20 events in sniff it's hard to be sure how exactly he performs those events.
UPDATE `creature` SET `VerifiedBuild` = 15354 WHERE `id` IN (25639,25644);
UPDATE `creature` SET `position_x` = 1751.93, `position_y` = 930.868, `position_z` = 15.6551, `orientation` = 6.09832 WHERE `guid` = 48391 AND `id` = 25639;

DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 36 AND 38;
DELETE FROM `waypoint_data` WHERE `id` = 483910;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(483910,1,1763.8091,930.536,15.575414,0,0,0,0,0,0),
(483910,2,1770.3094,930.33466,15.574421,0,0,0,0,0,0),
(483910,3,1776.947,929.85675,15.573964,0,0,0,0,0,0),
(483910,4,1778.0049,924.19366,15.585295,0,0,0,0,0,0),
(483910,5,1774.9177,920.24884,15.594013,0,0,0,0,0,0),
(483910,6,1769.5209,918.2831,15.6212015,0,0,0,0,0,0),
(483910,7,1761.9933,918.35004,15.614966,0,0,0,0,0,0),
(483910,8,1756.4244,918.3069,15.610523,0,0,0,0,0,0),
(483910,9,1752.59,918.36414,15.607305,0,0,0,0,0,0),
(483910,10,1751.6005,921.10004,15.60151,0,0,0,0,0,0),
(483910,11,1751.7445,926.3292,15.592088,0,0,0,0,0,0),
(483910,12,1754.5441,930.37946,15.586972,0,0,0,0,0,0),
(483910,13,1758.4761,930.43427,15.590065,0,0,0,0,0,0);

UPDATE `creature_template` SET `AIName` = "SmartAI", `npcflag` = 0 WHERE `entry` = 25639;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25639 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2563900 AND 2563901 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Phases controls initial timers and repeat timers
(25639,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Respawn - Set Event Phase 1"),
(25639,0,1,0,1,1,100,0,20000,60000,20000,60000,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - Out of Combat - Set Event Phase 2 (Phase 1)"),
(25639,0,2,0,34,2,100,0,2,0,0,0,0,87,2563900,2563900,2563900,2563901,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Reached Point - Run Random Script (Phase 2)"),

(2563900,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Event Phase 0"),
(2563900,9,1,0,0,0,100,0,1000,2500,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Pause Waypoint"),
(2563900,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,25661,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Orientation Closest Creature 'Shattered Sun Soldier'"),
(2563900,9,3,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Flag Standstate Kneel"),
(2563900,9,4,0,0,0,100,0,7000,7000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Remove Flag Standstate Kneel"),
(2563900,9,5,0,0,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Event Phase 1"),

(2563901,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Event Phase 0"),
(2563901,9,1,0,0,0,100,0,1000,2500,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Pause Waypoint"),
(2563901,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,25661,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Orientation Closest Creature 'Shattered Sun Soldier'"),
(2563901,9,3,0,0,0,100,0,0,0,0,0,0,11,45859,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Cast 'Renew'"),
(2563901,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Say Line 0"),
(2563901,9,5,0,0,0,100,0,5000,5000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Elbadon - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 25639;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25639,0,0,"May the light bless you.",12,0,100,1,0,0,24856,0,"Anchorite Elbadon"),
(25639,0,1,"Your wounds are severe, but you will live.",12,0,100,1,0,0,24857,0,"Anchorite Elbadon"),
(25639,0,2,"Rest now, you have fought well today.",12,0,100,1,0,0,24858,0,"Anchorite Elbadon");

-- Neophyte Narama
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 34 AND 35;
DELETE FROM `waypoint_data` WHERE `id` = 483810;
UPDATE `creature` SET `MovementType` = 0 WHERE `guid` = 48381 AND `id` = 25644;
DELETE FROM `creature_addon` WHERE `guid` = 48381;

DELETE FROM `waypoints` WHERE `entry` = 25644;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(25644,1,1769.6271,923.52563,15.588467,"Neophyte Narama"),
(25644,2,1770.8618,921.8461,15.591629,"Neophyte Narama"),
(25644,3,1762.8635,925.4075,15.602798,"Neophyte Narama"),
(25644,4,1758.3658,922.5452,15.604367,"Neophyte Narama"),
(25644,5,1755.8882,924.14954,15.599429,"Neophyte Narama");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 25644;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25644 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2564400 AND 2564403 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25644,0,0,0,63,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Just Created - Set Flag Standstate Kneel"),
(25644,0,1,2,1,0,100,1,20000,20000,0,0,0,53,0,25644,1,0,0,2,1,0,0,0,0,0,0,0,0,"Neophyte Narama - Out of Combat - Start Waypoint (No Repeat)"),
(25644,0,2,0,61,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Link - Remove Flag Standstate Kneel"),
(25644,0,3,0,40,0,100,0,2,0,0,0,0,88,2564400,2564403,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Waypoint 2 Reached - Run Random Script"),
(25644,0,4,0,40,0,100,0,3,0,0,0,0,88,2564400,2564403,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Waypoint 3 Reached - Run Random Script"),
(25644,0,5,0,40,0,100,0,5,0,0,0,0,88,2564400,2564403,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Waypoint 5 Reached - Run Random Script"),

(2564400,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Pause Waypoint"),
(2564400,9,1,0,0,0,100,0,0,1500,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Set Flag Standstate Kneel"),
(2564400,9,2,0,0,0,100,0,15000,15000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Resume Waypoint"),
(2564400,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Remove Flag Standstate Kneel"),

(2564401,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Pause Waypoint"),
(2564401,9,1,0,0,0,100,0,0,1500,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Set Flag Standstate Kneel"),
(2564401,9,2,0,0,0,100,0,20000,20000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Resume Waypoint"),
(2564401,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Remove Flag Standstate Kneel"),

(2564402,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Pause Waypoint"),
(2564402,9,1,0,0,0,100,0,0,1500,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Set Flag Standstate Kneel"),
(2564402,9,2,0,0,0,100,0,25000,25000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Resume Waypoint"),
(2564402,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Remove Flag Standstate Kneel"),

(2564403,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Pause Waypoint"),
(2564403,9,1,0,0,0,100,0,0,1500,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Set Flag Standstate Kneel"),
(2564403,9,2,0,0,0,100,0,30000,30000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Resume Waypoint"),
(2564403,9,3,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Neophyte Narama - On Script - Remove Flag Standstate Kneel");

-- Kil'jaeden, Anveena
UPDATE `creature_template_movement` SET `Swim` = 0, `Rooted` = 1 WHERE `CreatureID` = 25315;
UPDATE `creature_template_movement` SET `Flight` = 1 WHERE `CreatureID` = 26046;

-- Black Rat
UPDATE `creature` SET `wander_distance` = 10, `MovementType` = 1 WHERE `id` = 2110 AND `map` = 580;
