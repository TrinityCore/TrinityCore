-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (14026,14029,14028,14027,14030,14031,27339,32926);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(14026, 0, 0, 1, 0),
(14029, 0, 0, 1, 0),
(14028, 0, 0, 1, 0),
(14027, 0, 0, 1, 0),
(14030, 0, 0, 1, 0),
(14031, 0, 0, 1, 0),
(27339, 0, 0, 1, 0),
(32926, 1, 1, 0, 1);

DELETE `ctm` FROM `creature_template_movement` `ctm` INNER JOIN `creature_template` `ct` ON `ctm`.`CreatureId` = `ct`.`difficulty_entry_1`;
DELETE `ctm` FROM `creature_template_movement` `ctm` INNER JOIN `creature_template` `ct` ON `ctm`.`CreatureId` = `ct`.`difficulty_entry_2`;
DELETE `ctm` FROM `creature_template_movement` `ctm` INNER JOIN `creature_template` `ct` ON `ctm`.`CreatureId` = `ct`.`difficulty_entry_3`;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) SELECT `diff_entry`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random` FROM `creature_template_movement` `ctm` JOIN (SELECT `entry`, `difficulty_entry_1` AS `diff_entry`  FROM `creature_template`  WHERE `difficulty_entry_1` > 0) `ct` ON `ctm`.`CreatureId` = `ct`.`entry`;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) SELECT `diff_entry`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random` FROM `creature_template_movement` `ctm` JOIN (SELECT `entry`, `difficulty_entry_2` AS `diff_entry`  FROM `creature_template`  WHERE `difficulty_entry_2` > 0) `ct` ON `ctm`.`CreatureId` = `ct`.`entry`;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) SELECT `diff_entry`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random` FROM `creature_template_movement` `ctm` JOIN (SELECT `entry`, `difficulty_entry_3` AS `diff_entry`  FROM `creature_template`  WHERE `difficulty_entry_3` > 0) `ct` ON `ctm`.`CreatureId` = `ct`.`entry`;
