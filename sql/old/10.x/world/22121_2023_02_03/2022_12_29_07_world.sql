SET @CGUID := 396705;
SET @OGUID := 253205;
SET @EVENT := 2;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (89403, 89404);
DELETE FROM `game_event_creature` WHERE `guid` IN (89403, 89404);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Falconwing Square
(@CGUID+0, 15760, 530, 3430, 3665, '0', 0, 0, 0, 1, 9473.97265625, -6862.70166015625, 17.46774101257324218, 5.480333805084228515, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213), -- Winter Reveler (Area: Falconwing Square - Difficulty: 0)
(@CGUID+1, 15760, 530, 3430, 3665, '0', 0, 0, 0, 1, 9475.212890625, -6864.0849609375, 17.44821739196777343, 2.30383467674255371, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 47213); -- Winter Reveler (Area: Falconwing Square - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+0, @CGUID+1);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '39860'), -- 15760 (Winter Reveler)
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 0, '39861'); -- 15760 (Winter Reveler)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=41488;
DELETE FROM `game_event_gameobject` WHERE `guid`=41488;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
-- Falconwing Square
(@OGUID+0, 180844, 530, 3430, 3665, '0', 0, 0, 9474.619140625, -6863.3203125, 23.58727455139160156, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 47213); -- Mistletoe (Area: Falconwing Square - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid`=@OGUID+0;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0);
