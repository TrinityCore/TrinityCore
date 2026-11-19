--
DELETE FROM `creature_movement_override` WHERE `SpawnId` IN (117664, 117670, 117671, 117672, 117677);
INSERT INTO `creature_movement_override` (`SpawnId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(117664, 1, 0, 1, 0),
(117670, 1, 0, 1, 0),
(117671, 1, 0, 1, 0),
(117672, 1, 0, 1, 0),
(117677, 1, 0, 1, 0);
