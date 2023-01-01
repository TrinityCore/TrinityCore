-- Warsong Battle Standard
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 26678;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(26678, 1, 0, 0, 1);
