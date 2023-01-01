--
UPDATE `creature_template` SET `scale` = 1 WHERE `entry` IN (28440,32498);
DELETE FROM `creature_template_addon` WHERE `entry` IN (28407,32498);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(28407,0,0,0,1,0,0,"51583"),
(32498,0,0,0,1,0,0,"51583");
