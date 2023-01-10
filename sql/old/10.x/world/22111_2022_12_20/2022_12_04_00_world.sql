SET @OGUID := 248207;
SET @EVENT := 12;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 186614, 1, 14, 362, '0', 0, 0, 354.647125244140625, -4739.91552734375, 9.8121490478515625, 6.056293010711669921, 0, 0, -0.11320304870605468, 0.993571877479553222, 120, 255, 1, 46340); -- Water Bucket (Area: Razor Hill - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid`=@OGUID+0;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0);
