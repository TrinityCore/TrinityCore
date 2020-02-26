-- 
-- Pathing for Motega Firemane
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=21693;
DELETE FROM `creature_addon` WHERE `guid`=21693;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(21693,216930,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=216930;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(216930,1,-4915.57,-1381.18,-52.6008,5.14872,60000,0,216930,100,0),
(216930,2,-4913.27,-1379.59,-52.6119,0,0,0,0,100,0),
(216930,3,-4911.95,-1376.93,-52.6119,0,0,0,0,100,0),
(216930,4,-4913.82,-1376.04,-52.6119,0,15000,0,0,100,0),
(216930,5,-4915.75,-1378.4,-52.6119,0,0,0,0,100,0),
(216930,6,-4918.77,-1378.01,-52.6119,0,0,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id`=216930;
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(216930,1,1,23,0,0,0,0,0,0,953);
