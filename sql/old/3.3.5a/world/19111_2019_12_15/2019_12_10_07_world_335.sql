-- 
DELETE FROM `creature` WHERE `guid` IN (120641, 120642, 120643);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120641, 34281, 1, 1, 1, 0, 0, -963.143, -3766.15, 5.37971, 0, 180, 0, 0, 0, 0, 0),
(120642, 34281, 1, 1, 1, 0, 0, -997.826, -3822.7, 5.42039, 0, 180, 0, 0, 0, 0, 0),
(120643, 34281, 1, 1, 1, 0, 0, 9934.07, 2501.45, 1317.91, 0, 180, 0, 0, 0, 0, 0);

DELETE FROM `game_event_creature` WHERE `guid` IN (120641, 120642, 120643);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(10,120641),
(10,120642),
(10,120643);
