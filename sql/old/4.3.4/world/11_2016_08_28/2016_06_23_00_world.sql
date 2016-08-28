--
SET @CGUID := 250016;
DELETE FROM creature WHERE `guid` = @CGUID;
INSERT INTO creature (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 37024, 1, 0, 0, 1, 0, 0, 0, 0, -798.2708, -486.757, -32.19226, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15354);
