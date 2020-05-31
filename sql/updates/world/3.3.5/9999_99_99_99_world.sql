DELETE FROM `creature_template_movement` WHERE `CreatureId` = 29281 OR `CreatureId` = 26668 or `CreatureId` = 30809;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(29281, 1, 0, 1, 0, 0, 0),
(26668, 2, 0, 1, 0, 0, 0),
(30809, 2, 0, 1, 0, 0, 0);
