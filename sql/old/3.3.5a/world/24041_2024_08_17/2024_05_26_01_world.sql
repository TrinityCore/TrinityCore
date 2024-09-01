-- Add 3 gameobjects in Shattrath - Aldor Rise
DELETE FROM `gameobject` WHERE `guid` IN (9898,9899,9900) AND `id` IN (194466,194467,194468);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(9898, 194466, 530, 0, 0, 1, 1, -1737.48095703125, 5632.6103515625, 128.9701995849609375, 0, 0, 0, 0, 1, 120, 255, 1, '', 54847), -- Alchemy Lab
(9899, 194467, 530, 0, 0, 1, 1, -1745.2545166015625, 5646.84228515625, 128.023193359375, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 120, 255, 1, '', 54847), -- Blacksmith's Anvil
(9900, 194468, 530, 0, 0, 1, 1, -1747.6688232421875, 5648.66162109375, 128.023193359375, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 120, 255, 1, '', 54847); -- Forge
