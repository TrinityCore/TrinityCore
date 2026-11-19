-- 
DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (31204,31547);
INSERT INTO `creature_template_movement` (`CreatureID`, `Ground`, `Swim`, `Rooted`) VALUES
(31204,1,1,1),
(31547,1,1,1);
