-- Smoldering Skeleton Visual
DELETE FROM `creature_template_addon` WHERE `entry` IN (27360, 27356);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(27360, 0, 0x0, 0x1, '48454 51437'); -- 27360 - 48454, 51437
