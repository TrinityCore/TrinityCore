ALTER TABLE `creature_template_movement` ADD `Chase` tinyint(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_movement_override` ADD `Chase` tinyint(3) UNSIGNED NOT NULL DEFAULT '0';

DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (20064,28654);
INSERT INTO `creature_template_movement` (`CreatureID`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`) VALUES
(20064,1,0,0,0,2),
(28654,1,0,0,0,2);
