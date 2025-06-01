--
UPDATE `creature` SET `MovementType` = 0 WHERE `guid` = 66999;

DELETE FROM `creature_addon` WHERE `guid` = 66999;
DELETE FROM `script_waypoint` WHERE `entry` = 18731;
DELETE FROM `waypoint_data` WHERE `id` = 669990;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(669990,1,-159.51387,-2.139098,8.0730915,NULL,0,0,0,100,0),
(669990,2,-172.266,-18.28,8.073,NULL,0,0,0,100,0),
(669990,3,-171.051,-38.748,8.073,NULL,0,0,0,100,0),
(669990,4,-170.718,-59.436,8.073,NULL,0,0,0,100,0),
(669990,5,-156.659,-72.118,8.073,NULL,0,0,0,100,0),
(669990,6,-142.292,-59.423,8.073,NULL,0,0,0,100,0),
(669990,7,-141.779,-38.972,8.073,NULL,0,0,0,100,0),
(669990,8,-142.922,-18.95,8.073,NULL,0,0,0,100,0),
(669990,9,-157.366,2.177,8.073,NULL,0,0,0,100,0);

-- Not used
DELETE FROM `creature_text` WHERE `CreatureID` = 18731 AND `GroupID` = 0;

-- This one is spawned after Blackheart, makes it impossible to unbanish Hellmaw without killing Blackheart and this NPC
-- We just change it to another pooled entry
UPDATE `creature` SET `id` = 18848 WHERE `guid` = 66854;
