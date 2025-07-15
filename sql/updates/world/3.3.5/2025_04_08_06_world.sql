-- "Mist" more blizzlike script

-- Mist respawn time, time is from classic server
UPDATE `creature` SET `spawntimesecs`=30 WHERE `guid`=49625;

-- Mist Waypoints
DELETE FROM `waypoints` WHERE `entry`=3568;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(3568,1,10657.489,1849.751,1321.866,"Mist"),
(3568,2,10647.716,1808.649,1326.796,"Mist"),
(3568,3,10661.571,1771.858,1322.714,"Mist"),
(3568,4,10726.747,1753.344,1314.693,"Mist");

-- Sentinel Arynia Cloudsbreak missing text emote
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=3519 AND `ID`=0;

-- Mist's contact sensitivity distance to Sentinel Arynia Cloudsbreak
UPDATE `smart_scripts` SET `event_param3`=5 WHERE `entryorguid`=3568 AND `id`=1;

-- Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=3568 AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (351900,356801) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES

-- Mist Script
(3568,0,4,0,40,0,100,0,4,3568,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Waypoint 4 Reached - Despawn"),

-- Sentinel Arynia Cloudsbreak Timed list
(351900,9,0,0,0,0,100,0,1000,1000,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Remove Quest Giver npc flag"),
(351900,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,3568,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Orientation"),
(351900,9,2,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Flag Standstate 'Kneel'"),
(351900,9,3,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Say Line 0"),
(351900,9,4,0,0,0,100,0,7000,7000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Remove Flag Standstate 'Kneel'"),
(351900,9,5,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Set Orientation"),
(351900,9,6,0,0,0,100,0,500,500,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentinel Arynia Cloudsbreak - On Script - Add Quest Giver npc flag"),

-- Mist Timed list
(356801,9,0,0,0,0,100,0,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Set Root On"),
(356801,9,1,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,3519,0,0,0,0,0,0,0,"Mist - On Script - Set Data to 'Sentinel Arynia Cloudsbreak'"),
(356801,9,2,0,0,0,100,0,2000,2000,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Set Root Off"),
(356801,9,3,0,0,0,100,0,0,0,0,0,0,15,938,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Mist - On Script - Complete Quest 'Mist'"),
(356801,9,4,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Set Run Off"),
(356801,9,5,0,0,0,100,0,0,0,0,0,0,69,0,0,0,1,0,0,19,3519,0,0,0,0,0,0,0,"Mist - On Script - Move to 'Sentinel Arynia Cloudsbreak'"),
(356801,9,6,0,0,0,100,0,9000,9000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Say Line 0"),
(356801,9,7,0,0,0,100,0,0,0,0,0,0,145,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Set Immune to NPC's"),
(356801,9,8,0,0,0,100,0,3000,3000,0,0,0,53,1,3568,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mist - On Script - Start Waypoints");
