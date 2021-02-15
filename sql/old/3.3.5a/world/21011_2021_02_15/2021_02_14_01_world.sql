--
UPDATE `creature_template` SET `minlevel` = 1, `maxlevel` = 1, `speed_run` = 0.85714285714, `RangeAttackTime` = 2000, `unit_flags` = 33536 WHERE `entry` = 11327;
DELETE FROM `creature_template_addon` WHERE `entry` = 11327;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(11327,0,0,0,1,0,0,"67399");
UPDATE `creature_model_info` SET `BoundingRadius` = 0.105, `CombatReach` = 0.25 WHERE `DisplayID` = 10993;

UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 34694;
DELETE FROM `creature_template_addon` WHERE `entry` = 34694;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(34694,0,0,0,1,0,0,"67370");
UPDATE `creature_model_info` SET `BoundingRadius` = 0.22749999 WHERE `DisplayID` = 29348;
