SET @OGUID := 400420;

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 240291, 1220, 7334, 7364, '0', 0, 0, -137.583328247070312, 6983.27978515625, 8.014510154724121093, 1.862035393714904785, 0, 0, 0.802227973937988281, 0.597017824649810791, 120, 255, 0, 46455); -- Demon Ward
