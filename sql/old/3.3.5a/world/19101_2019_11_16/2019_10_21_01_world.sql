-- 
DELETE FROM `creature` WHERE `guid` IN (117317,117318,117319);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(117317, 30685, 571, 210, 4504, 1, 128, 0, 1, 6370.581, 227.0712, 396.1292, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 30685 (Area: 4504 - Difficulty: 0)
(117318, 30685, 571, 210, 4504, 1, 128, 0, 1, 6378.393, 229.9219, 396.1292, 0.9250245, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340), -- 30685 (Area: 4504 - Difficulty: 0)
(117319, 30685, 571, 210, 4504, 1, 128, 0, 1, 6378.936, 224.7951, 396.1292, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 30685 (Area: 4504 - Difficulty: 0)

UPDATE `creature` SET `position_x`=6371.885, `position_y`=237.8247, `position_z`=396.1291, `orientation`=1.710423 WHERE `id`=30686;
