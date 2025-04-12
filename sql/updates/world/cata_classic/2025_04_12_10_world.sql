-- Put Garrosh back onto his throne
UPDATE `creature` SET `position_x`= 1669.5851, `position_y`= -4343.08, `position_z`= 28.446056, `orientation`= 3.612831592559814453 WHERE `guid`= 310903;

-- Updating the Reforger and Transmogrifier in Orgrimmar for Classic
DELETE FROM `creature` WHERE `guid`= 370880;
DELETE FROM `creature_addon` WHERE `guid`= 370880;

SET @CGUID := 3990094;
DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID, 54471, 1, 1637, 5170, '0', 169, 0, 0, 1, 1721.1353759765625, -4513.19287109375, 31.32893943786621093, 0.314159274101257324, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60192); -- Thaumaturge Zajir (Area: Valley of Strength - Difficulty: 0) CreateObject1

UPDATE `creature_template` SET `npcflag`=268435456 WHERE `entry`=54473; -- Warpweaver Dushar
DELETE FROM `creature_template_gossip` WHERE `CreatureID`= 54473;
