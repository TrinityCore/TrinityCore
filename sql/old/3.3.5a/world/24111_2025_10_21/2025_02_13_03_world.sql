-- Fix for "Cleansing of the Orb of Orahil" quest event
-- Tabetha Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=6546 AND `id`IN (0,11,12,13);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (654600,654607,654608) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6546,0,0,0,19,0,100,0,4961,0,0,0,0,80,654600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Quest 'Cleansing of the Orb of Orahil' Taken - Run Script"),
(6546,0,11,12,40,0,100,0,4,6546,0,0,0,80,654607,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Waypoint 4 Reached - Run Script"),
(6546,0,12,0,61,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Link - Set Run On"),
(6546,0,13,0,40,0,100,0,9,6546,0,0,0,80,654608,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Waypoint 9 Reached - Run Script"),

-- Tabetha Timed List 1
(654600,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Script - Remove Npc Flag Questgiver+Gossip"),
(654600,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Script - Say Line 0"),
(654600,9,2,0,0,0,100,0,0,0,0,0,0,53,0,6546,0,0,0,0,0,0,0,0,0,0,0,0,0,"Tabetha - On Script - Start Waypoint"),

-- Tabetha Timed List 8
(654607,9,0,0,0,0,100,0,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Script - Pause Waypoint"),
(654607,9,1,0,0,0,100,0,1000,1000,0,0,0,11,9097,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Script - Cast Summon Demon of the Orb"),

-- Tabetha Timed List 9
(654608,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,2.0822,"Tabetha - On Script - Reset Orientation"),
(654608,9,1,0,0,0,100,0,1000,1000,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tabetha - On Script - Add Npc Flag Questgiver+Gossip");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=6546;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(6546,1,-4037.934,-3380.369,37.811,''),
(6546,2,-4036.560,-3377.986,37.762,''),
(6546,3,-4029.500,-3376.984,38.132,''),
(6546,4,-4019.693,-3381.410,38.228,'Tabetha_SUMMON'),
(6546,5,-4029.500,-3376.984,38.132,''),
(6546,6,-4036.560,-3377.986,37.762,''),
(6546,7,-4037.934,-3380.369,37.811,''),
(6546,8,-4034.080,-3388.858,38.997,''),
(6546,9,-4031.560,-3392.970,38.997,'Tabetha_STOP');

-- Conditions to prevent Tabetha from stopping and summoning another Demon if one is already present
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=654607 AND `SourceId`=9;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,654607,9,0,29,1,6549,100,0,1,0,0,"","Smart Event 1 for creature Tabetha only executes if creature 'Demon of the Orb' not near"),
(22,2,654607,9,0,29,1,6549,100,0,1,0,0,"","Smart Event 2 for creature Tabetha only executes if creature 'Demon of the Orb' not near");
