--
UPDATE `creature_template_movement` SET `Flight`= 1 WHERE `CreatureId` IN (26174, 26483, 24440, 24747, 28246, 29460, 29808, 32630, 30575, 30482, 31137, 32767, 31702, 32189, 32201, 32492, 28170, 28004, 28378, 28086, 28085, 30988, 33550, 30275);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (29792, 29793);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`) VALUES
(29792, 1, 1),
(29793, 1, 1);
