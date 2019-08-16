-- 
UPDATE `creature` SET `MovementType`=1, `spawndist`=3 WHERE `guid` IN (88917,88916);

DELETE FROM `creature` WHERE `guid`=79457;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(79457, 27707, 1, 14, 0, 1, 1, 0, 0, 1290.452, -4431.32, 27.10891, 5.220081, 120, 3, 0, 0, 0, 1, 0, 0, 0, 12340); -- 27707 (Area: 0 - Difficulty: 0)

DELETE FROM `game_event_creature` WHERE `guid`=79457;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24, 79457);
