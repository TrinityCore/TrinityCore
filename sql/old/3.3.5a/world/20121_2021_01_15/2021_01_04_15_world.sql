--
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (16972,17035,17053,20069,20142);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(16972,1,0,0,0,0,0),
(17035,1,0,0,0,0,0),
(17053,1,0,0,0,0,0),
(20069,1,0,0,0,0,0),
(20142,1,0,0,0,0,0);
