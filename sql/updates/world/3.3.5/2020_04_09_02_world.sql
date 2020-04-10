-- 
UPDATE `creature_template` SET `minlevel`=73, `maxlevel`=73 WHERE `entry`=31104;
DELETE FROM `creature_template_addon` WHERE `entry`=31449;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(31449, 0, 0, 0, 1, 0, 0, "18950");
