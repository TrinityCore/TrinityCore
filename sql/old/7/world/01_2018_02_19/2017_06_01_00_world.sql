-- Cataclysm spawns
SET @C_OGUID:=200624;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @C_OGUID+0 AND @C_OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@C_OGUID+0, 207692, 0, 0, 0, 1, 169, 0, -8212.33,  399.0208, 117.273,  1.649333,          0, 0,          0.7343216, 0.6788017, 120, 255, 1, 23420), -- Portal to Hyjal (Area: Stormwind City)
(@C_OGUID+1, 207693, 0, 0, 0, 1, 169, 0, -8223.319, 451.1823, 117.4883, 3.141593,          0, 0,                 -1, 0,         120, 255, 1, 23420), -- Portal to Deepholm (Area: Stormwind City)
(@C_OGUID+2, 207695, 0, 0, 0, 1, 169, 0, -8233.281, 415.5955, 117.4477, 3.839726,-0.02000666, 0.01454353,-0.9395018, 0.3416499, 120, 255, 1, 23420), -- Portal to Uldum (Area: Stormwind City)
(@C_OGUID+3, 207694, 0, 0, 0, 1, 169, 0, -8186.149, 413.7292, 116.7497, 2.722713,          0, 0,          0.9781475, 0.2079121, 120, 255, 1, 23420); -- Portal to Twilight Highlands (Area: The Eastern Earthshrine)
