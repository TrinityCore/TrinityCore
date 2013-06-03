-- Razorscale
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (33186,33724);

DELETE FROM `creature_template_addon` WHERE `entry` IN (33186,33724);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(33186, 0, 0x3000000, 0x1, ''),
(33724, 0, 0x3000000, 0x1, '');
