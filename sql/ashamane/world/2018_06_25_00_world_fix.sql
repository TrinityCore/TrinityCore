UPDATE `creature_template` SET `minlevel` = 0 WHERE `minlevel` = 110 AND (`HealthScalingExpansion` = -1);
UPDATE `creature_template` SET `maxlevel` = 0 WHERE `maxlevel` = 110 AND (`HealthScalingExpansion` = -1);
UPDATE `creature_template` SET `minlevel` = 1 WHERE `minlevel` = 111 AND (`HealthScalingExpansion` = -1);
UPDATE `creature_template` SET `maxlevel` = 1 WHERE `maxlevel` = 111 AND (`HealthScalingExpansion` = -1);
UPDATE `creature_template` SET `minlevel` = 3 WHERE `minlevel` = 113 AND (`HealthScalingExpansion` = -1);
UPDATE `creature_template` SET `maxlevel` = 3 WHERE `maxlevel` = 113 AND (`HealthScalingExpansion` = -1);

DELETE FROM `creature_template_addon` WHERE `entry` = 68;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(68, 0, 0, 0, 257, 0, 0, 0, 0, '');
