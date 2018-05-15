-- 
DELETE FROM `creature` WHERE `guid` IN (252243);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(252243, 29712, 0, 4922, 5470, 1, 169, 0, 0, 0, -8641.44433, 951.4826, 98.2429, 4.897644, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Stormwind Harbor Guard (Area: Victor's Point - Difficulty: 0) (Auras: )
DELETE FROM `creature_addon` WHERE `guid` IN (252243);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(252243, 0, 0, 0, 257, 0, ''); -- Stormwind Harbor Guard
