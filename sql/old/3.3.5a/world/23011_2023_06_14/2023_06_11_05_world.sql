-- Add two missing mailbox in Moonglade Nighthaven
DELETE FROM `gameobject` WHERE `guid` IN (100507, 100508);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(100507, 195218, 1, 0, 0, 1, 1, 8008.7421875, -2668.053955078125, 512.06414794921875, 2.757613182067871093, 0, 0, 0.981626510620117187, 0.190812408924102783, 120, 255, 1, 0),
(100508, 195219, 1, 0, 0, 1, 1, 7867.26904296875, -2575.546875, 486.91259765625, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 120, 255, 1, 0);
