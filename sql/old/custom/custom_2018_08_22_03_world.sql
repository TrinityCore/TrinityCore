DELETE FROM `creature` WHERE `guid` IN (361804, 361805, 361806, 361807);
DELETE FROM `creature_addon` WHERE `guid` IN (361804, 361805, 361806, 361807);

DELETE FROM `creature_template_addon` WHERE `entry`= 40015;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40015, '77783');
