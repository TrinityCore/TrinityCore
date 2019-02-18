DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (46304, 44214, 45322);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`) VALUES
(46304, 2, 0),
(44214, 2, 1),
(45322, 2, 1);

