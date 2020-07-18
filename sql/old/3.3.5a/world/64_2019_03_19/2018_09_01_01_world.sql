-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (36853, 38265, 38266, 38267);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(36853, 1, 0, 2, 0),
(38265, 1, 0, 2, 0),
(38266, 1, 0, 2, 0),
(38267, 1, 0, 2, 0);
