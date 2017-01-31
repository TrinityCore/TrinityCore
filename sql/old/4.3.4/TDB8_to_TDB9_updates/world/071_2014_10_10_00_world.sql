UPDATE `creature_template` SET `unit_flags`=320, `flags_extra`=2 WHERE `entry` IN(36065,36066); 
DELETE FROM `creature_template_addon` WHERE `entry` IN(36066, 36065);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(36066, 0, 0x2000000, 0x1, ''),
(36065, 0, 0x2000000, 0x1, '');
