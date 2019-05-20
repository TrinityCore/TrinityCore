DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (35592,54348,54367,53433,53129,54401,54402,52498);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(35592, 1, 1, 0),
(54348, 1, 1, 0),
(54367, 1, 1, 0),
(53433, 1, 1, 0),
(53129, 1, 1, 0),
(54401, 1, 1, 1),
(54402, 1, 1, 1),
(52498, 1, 1, 1);

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 42389;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`) VALUES
(42389, 1);
