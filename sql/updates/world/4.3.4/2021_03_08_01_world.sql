DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (5983, 42235, 42338);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`) VALUES
(5983, 2, 1),
(42235, 2, 1),
(42338, 2, 1);
