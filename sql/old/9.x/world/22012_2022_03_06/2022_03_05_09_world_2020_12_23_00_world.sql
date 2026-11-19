--
UPDATE `creature` SET `modelid` = 25723 WHERE `id` = 33264;
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 33264;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(33264,1,0,0,1,0,0);
