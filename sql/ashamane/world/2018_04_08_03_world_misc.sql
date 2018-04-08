-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `npcflag` = 128 WHERE (entry = 121282);
UPDATE `creature_template` SET `npcflag` = 128 WHERE (entry = 99976);
UPDATE `creature_template` SET `npcflag` = 131 WHERE (entry = 101097);

-- Table `creature`
DELETE FROM `creature` WHERE (id = 121282);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(210112066, 121282, 1220, 0, 0, 1, 0, 0, 0, -1, 0, 0, -965.555, 4545.66, 698.156, 0.304701, 300, 0, 0, 87, 0, 0, 0, 0, 0, 0, 0, '', 0);
