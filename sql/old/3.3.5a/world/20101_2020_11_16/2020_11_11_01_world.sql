-- Not sure how exactly double summon should be prevented. Best guess spell focus just despawns on event start and respawns after event end
UPDATE `gameobject` SET `spawntimesecs` = 60 WHERE `id` = 184834;
UPDATE `gameobject_template` SET `AIName` = "" WHERE `entry` IN (184834,184835);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (184834,184835) AND `source_type` = 1;

UPDATE `event_scripts` SET `datalong2` = 120000, `x` = -3310.8516, `y` = 2951.6367, `z` = 171.20958, `o` = 5.224671363830566406, `Comment` = "Event (Spell 'Crate Disguise Subspell' (37492)) - On Event - Summon Creature 'Deathbringer Jovaan'" WHERE `id` = 13852;

UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 0.91269, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 768 WHERE `entry` IN (21633,21502);

UPDATE `creature_text` SET `Emote` = 66 WHERE `CreatureID` = 21633 AND `GroupID` = 2;

UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 21502;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21633,21502) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2163300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21633,0,0,1,63,0,100,0,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Just Created - Cast 'Ethereal Teleport'"),
-- Should be despawned by event script
(21633,0,1,2,61,0,100,0,0,0,0,0,0,41,0,60,0,0,0,0,20,184834,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Link - Despawn Closest Gameobject 'Infernal'"),
(21633,0,2,0,61,0,100,0,0,0,0,0,0,53,0,21633,0,0,0,2,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Link - Start Waypoint"),
(21633,0,3,0,40,0,100,0,3,0,0,0,0,80,2163300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Waypoint 3 Reached - Run Script"),
(21633,0,4,0,40,0,100,0,6,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Waypoint 6 Reached - Despawn (1000)"),

(2163300,9,0,0,0,0,100,0,3000,3000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Play Emote 25"),
(2163300,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 0"),
(2163300,9,2,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Set Flag Standstate Kneel"),
(2163300,9,3,0,0,0,100,0,0,0,0,0,0,12,21502,8,60000,0,0,0,8,0,0,0,0,-3300.09,2927.05,173.335,2.19912,"Deathbringer Jovaan - On Script - Summon Creature 'Image of Warbringer Razuun'"),
(2163300,9,4,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 0 (Image of Warbringer Razuun)"),
(2163300,9,5,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 1"),
(2163300,9,6,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 1 (Image of Warbringer Razuun)"),
(2163300,9,7,0,0,0,100,0,2000,2000,0,0,0,5,25,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Play Emote 25 (Image of Warbringer Razuun)"),
(2163300,9,8,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Remove Flag Standstate Kneel"),
(2163300,9,9,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 2"),
(2163300,9,10,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 2 (Image of Warbringer Razuun)"),
(2163300,9,11,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 3"),
(2163300,9,12,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Say Line 3 (Image of Warbringer Razuun)"),
(2163300,9,13,0,0,0,100,0,2000,2000,0,0,0,5,25,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Play Emote 25 (Image of Warbringer Razuun)"),
(2163300,9,14,0,0,0,100,0,3000,3000,0,0,0,33,21502,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Quest Credit 'To Legion Hold'"),
(2163300,9,15,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,19,21502,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Despawn Closest Creature 'Image of Warbringer Razuun'"),
(2163300,9,16,0,0,0,100,0,0,0,0,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathbringer Jovaan - On Script - Play Emote 66");

DELETE FROM `waypoints` WHERE `entry` = 21633;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(21633,1,-3307.9983,2942.0217,171.11267,0,0,"Deathbringer Jovaan"),
(21633,2,-3306.255,2935.7288,171.02937,0,0,"Deathbringer Jovaan"),
(21633,3,-3304.257,2930.78,170.98656,5.67231,47000,"Deathbringer Jovaan"),
(21633,4,-3307.6086,2936.3853,170.99191,0,0,"Deathbringer Jovaan"),
(21633,5,-3309.4153,2942.621,171.11896,0,0,"Deathbringer Jovaan"),
(21633,6,-3311.1133,2951.74,171.14693,0,0,"Deathbringer Jovaan");
