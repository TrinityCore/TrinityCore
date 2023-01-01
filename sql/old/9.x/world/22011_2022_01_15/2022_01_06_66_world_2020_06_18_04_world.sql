--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7868 AND `ConditionTypeOrReference` = 9;

UPDATE `smart_scripts` SET `link` = 2, `event_flags` = 0 WHERE `entryorguid` = 18956 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18956 AND `source_type` = 0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1895600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18956,0,1,0,40,0,100,0,9,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakka - On Waypoint 9 Reached - Despawn (0)"),
(18956,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lakka - On Link - Close Gossip"),

(1895600,9,0,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakka - On Script - Remove NPC Flag Gossip"),
(1895600,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lakka - On Script - Say Line 0"),
(1895600,9,2,0,0,0,100,0,0,0,0,0,0,33,18956,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Lakka - On Script - Quest Credit 'Brother Against Brother'"),
(1895600,9,3,0,0,0,100,0,2000,2000,0,0,0,9,0,0,0,0,0,0,14,67620,183051,0,0,0,0,0,0,"Lakka - On Script - Activate Gameobject 'Sethekk Cage'"),
(1895600,9,4,0,0,0,100,0,1000,1000,0,0,0,53,0,18956,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lakka - On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry` = 18956;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(18956,1,-156.81125,159.90024,0.55241066,"Lakka"),
(18956,2,-152.81125,162.15024,0.55241066,"Lakka"),
(18956,3,-148.56125,163.65024,0.55241066,"Lakka"),
(18956,4,-141.81125,164.90024,0.55241066,"Lakka"),
(18956,5,-136.06125,167.40024,0.55241066,"Lakka"),
(18956,6,-129.81125,171.40024,0.55241066,"Lakka"),
(18956,7,-118.06125,173.90024,0.55241066,"Lakka"),
(18956,8,-99.06125,173.40024,0.30241066,"Lakka"),
(18956,9,-79.80912,172.75728,0.010726,"Lakka");
