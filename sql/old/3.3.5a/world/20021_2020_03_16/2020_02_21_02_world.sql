-- 
DELETE FROM `creature` WHERE `guid` IN (1886, 94839, 94831, 94808, 94805, 94840, 94814, 94803);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(1886, 17066, 530, 0, 0, 1, 1, 0, 0,  -3821.98, -11508.3, -132.124, 0.9075, 180, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(94803, 17066, 530, 0, 0, 1, 1, 0, 0, -2988.84, 4126.660, 11, 3.26329, 180, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(94805, 17066, 571, 0, 0, 1, 1, 0, 0, 3943.700, -620.329, 249, 4.94546, 180, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(94808, 17066, 571, 0, 0, 1, 1, 0, 0, 5151.540, -709.361, 176.093, 2.02988, 180, 0, 0, 1, 0, 0, 0, 0, 0, 0);
DELETE FROM `game_event_creature` WHERE `guid` IN (1886, 94839, 94831, 94808, 94805, 94840, 94814, 94803); 
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(1,1886),(1,94803),(1,94805),(1,94808);
