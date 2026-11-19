UPDATE `creature_template` SET `flags_extra` = `flags_extra`| 0x200 WHERE `entry` IN (29281, 30809, 26668, 30810);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (29281, 30809, 26668, 30810);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES
(29281, 1, 0, 1, 0, 0, 0),
(30809, 1, 0, 1, 0, 0, 0),
(26668, 2, 0, 1, 0, 0, 0),
(30810, 2, 0, 1, 0, 0, 0);
