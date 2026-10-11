SET @CGUID := 8000020;
SET @OGUID := 8000020;

-- Creature templates
DELETE FROM `creature_template_addon` WHERE `entry` IN (165505);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(165505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 165505 (Loretta Banks)

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=165505 AND `DifficultyID`=0); -- 165505 (Loretta Banks) - CanSwim
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (165505) AND `DifficultyID`=1;

-- Gossips
UPDATE `creature_template_gossip` SET `VerifiedBuild`=57689 WHERE (`CreatureID`=165505 AND `MenuID`=25369) OR (`CreatureID`=167032 AND `MenuID`=25426) OR (`CreatureID`=89174 AND `MenuID`=14146);

-- Creature spawns
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 165505, 0, 1519, 1519, '0', 0, 0, 0, 0, -8450.576171875, 372.789947509765625, 135.7928619384765625, 5.341039180755615234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Loretta Banks (Area: Stormwind City - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 281118, 0, 1519, 1519, '0', 0, 0, -8450.7568359375, 376.12847900390625, 135.70953369140625, 6.11305093765258789, 0, 0, -0.08496475219726562, 0.996383965015411376, 120, 255, 1, 57689); -- Gryphon Roost (Area: Stormwind City - Difficulty: 0) CreateObject1
