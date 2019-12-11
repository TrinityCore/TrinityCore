-- 
DELETE FROM `creature` WHERE `guid` IN (120677);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120677, 36643, 33, 1, 1, 0, 0, -212.951, 2191.71, 79.8481, 0, 180, 0, 0, 0, 0, 0);

DELETE FROM `game_event_creature` WHERE `guid` IN (120677);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(8,120677);
