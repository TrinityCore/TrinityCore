SET @CGUID := 650469;

DELETE FROM `creature` WHERE `guid`=@CGUID+65;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+65, 111833, 1492, 7812, 7811, '1,2,8,23', 0, 0, 0, 0, 2933.046875, 848.609375, 515.24334716796875, 0, 7200, 0, 0, 100, 0, NULL, NULL, 45745); -- Thal'kiel (Area: -Unknown- - Difficulty: 23)

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry` IN(111833, 111221);
