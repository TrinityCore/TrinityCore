-- 
DELETE FROM `creature` WHERE `id`  IN (23488) AND `guid` IN (109935, 109988, 109997, 109998, 110004, 110005);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(109935, 23488, 1, 14, 1296, 1, 1, 0, 0, 1210.87, -4289.486, 21.63643, 0.5585054, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23488 (Area: 1296 - Difficulty: 0)
(109988, 23488, 1, 14, 1296, 1, 1, 0, 0, 1206.117, -4251.711, 24.29962, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23488 (Area: 1296 - Difficulty: 0)
(109997, 23488, 1, 14, 1296, 1, 1, 0, 0, 1245.652, -4280.512, 25.05864, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23488 (Area: 1296 - Difficulty: 0)
(109998, 23488, 0, 1, 0, 1, 1, 0, 0, -5175.604, -597.0005, 397.7565, 0.5585054, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23488 (Area: 0 - Difficulty: 0)
(110004, 23488, 0, 1, 0, 1, 1, 0, 0, -5122.557, -633.5287, 399.5836, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 23488 (Area: 0 - Difficulty: 0)
(110005, 23488, 0, 1, 0, 1, 1, 0, 0, -5105.744, -624.4401, 412.1684, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 23488 (Area: 0 - Difficulty: 0)

DELETE FROM `game_event_creature` WHERE `guid` IN (109935, 109988, 109997, 109998, 110004, 110005) AND `eventEntry`=24;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(24,109935),(24,109988),(24,109997),(24,109998),(24,110004),(24,110005);
