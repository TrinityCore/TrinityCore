UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (44687, 44600);
DELETE FROM `creature_template_addon` WHERE `entry` IN (46227, 46228, 46229);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES
(46227, 50331648, 1),
(46228, 50331648, 1),
(46229, 50331648, 1);
