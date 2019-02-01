-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (39747, 39823);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(39747, 2, 1, 2, 0),
(39823, 2, 1, 2, 0);
