DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (40765, 49064);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`) VALUES
(40765, 1, 0, 0),
(49064, 1, 0, 0);
