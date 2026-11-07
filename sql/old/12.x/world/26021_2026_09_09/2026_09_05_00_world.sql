SET @CGUID := 3000112;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 50009, 0, 5145, 5047, '0', 0, 0, 0, 0, -5417.732, 5257.314, -487.6926, 2.732448577880859375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 69382); -- Mobus (Area: Abyssal Breach - Difficulty: 0) CreateObject1 (Auras: 8876 - Thrash)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry`=50009;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(50009, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '8876'); -- 50009 (Mobus) - Thrash

-- Template
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x10000000 WHERE `entry`=50009; -- Mobus
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'worldboss_mobus' WHERE `entry` = 50009;

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=69382 WHERE (`Entry`=50009 AND `DifficultyID`=0); -- 50009 (Mobus) - CanSwim

-- Path for Mobus
SET @ENTRY := 50009;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.5828, 'Mobus - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -5417.732, 5257.314, -487.6926, NULL, 0),
(@PATH, 1, -5482.764, 5159.9873, -487.6926, NULL, 0),
(@PATH, 2, -5580.091, 5094.955, -487.6926, NULL, 0),
(@PATH, 3, -5694.896, 5072.119, -487.6926, NULL, 0),
(@PATH, 4, -5809.701, 5094.955, -487.6926, NULL, 0),
(@PATH, 5, -5907.028, 5159.9873, -487.6926, NULL, 0),
(@PATH, 6, -5972.06, 5257.314, -487.6926, NULL, 0),
(@PATH, 7, -5994.896, 5372.119, -487.6926, NULL, 0),
(@PATH, 8, -5972.06, 5486.9243, -487.6926, NULL, 0),
(@PATH, 9, -5907.0283, 5584.251, -487.6926, NULL, 0),
(@PATH, 10, -5809.701, 5649.283, -487.6926, NULL, 0),
(@PATH, 11, -5694.896, 5672.119, -487.6926, NULL, 0),
(@PATH, 12, -5580.091, 5649.283, -487.6926, NULL, 0),
(@PATH, 13, -5482.7637, 5584.251, -487.6926, NULL, 0),
(@PATH, 14, -5417.732, 5486.924, -487.6926, NULL, 0),
(@PATH, 15, -5394.896, 5372.119, -487.6926, NULL, 0);

UPDATE `creature_template_addon` SET `PathId` = 5000900 WHERE `entry` = 50009;
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 2 WHERE `guid` = @CGUID+0;
