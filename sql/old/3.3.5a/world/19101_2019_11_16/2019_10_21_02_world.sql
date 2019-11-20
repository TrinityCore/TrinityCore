-- 
DELETE FROM `creature` WHERE `guid` IN (117320);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(117320, 30719, 571, 210, 4501, 1, 128, 0, 0, 6368.458, 217.5608, 395.3252, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 12340); -- 30719 (Area: 4501 - Difficulty: 0)

UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry` IN (30719);
