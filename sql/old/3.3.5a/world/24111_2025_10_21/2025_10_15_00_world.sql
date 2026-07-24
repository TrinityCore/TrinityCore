--
SET @OGUID := 9905; -- Need 2
SET @EVENT := 24;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 186331, 0, 0, 0, 1, 1, -5493.53, -533.77, 398.3468, 4.70377, 0, 0, -0.710146, 0.704054, 180, 255, 1, 55262), -- Brewfest - Apple trap (Area: DunMorogh)
(@OGUID+1, 186717, 0, 0, 0, 1, 1, -5337.28, -544.06, 393.5129, 1.44194, 0, 0, -0.660114, -0.751165, 180, 255, 1, 55262); -- Brewfest - Brewfest Banner  (Area: DunMorogh)

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1 AND `eventEntry`=@EVENT;
INSERT INTO `game_event_gameobject` SELECT @EVENT, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+1;

UPDATE `gameobject` SET `position_x`=-5633.37, `position_y`=-491.68, `position_z`=396.6698, `orientation`=6.1775 WHERE  `guid`=31405;
UPDATE `gameobject` SET `position_x`=-5647.71, `position_y`=-477.88, `position_z`=396.3797, `orientation`=6.1775 WHERE  `guid`=31406;
UPDATE `gameobject` SET `position_x`=-5356.91, `position_y`=-536.86, `position_z`=391.7593, `orientation`=6.1775 WHERE  `guid`=31407;
