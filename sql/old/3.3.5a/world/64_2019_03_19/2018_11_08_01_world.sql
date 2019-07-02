UPDATE `creature_template` SET `HoverHeight`=6 WHERE `entry` IN (35347,35348,35349,35350,35351,35352);
UPDATE `creature_template_addon` SET `bytes1`=0x2000000 WHERE `entry` IN (34496,34497,35347,35348,35349,35350,35351,35352);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (34496,34497,35347,35348,35349,35350,35351,35352);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(34496,2,0,0,0),
(34497,2,0,0,0),
(35347,2,0,0,0),
(35348,2,0,0,0),
(35349,2,0,0,0),
(35350,2,0,0,0),
(35351,2,0,0,0),
(35352,2,0,0,0);
