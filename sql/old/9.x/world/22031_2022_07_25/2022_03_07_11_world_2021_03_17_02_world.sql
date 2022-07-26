--
UPDATE `creature_template_movement` SET `Ground` = 1 WHERE `CreatureId` IN (15241,15242,21976);
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (22067,22077,22085,22089,22122);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(22067,1,0,1,0,0,0),
(22077,1,0,1,0,0,0),
(22085,1,0,1,0,0,0),
(22089,1,0,1,0,0,0),
(22122,1,0,1,0,0,0);
