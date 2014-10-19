DELETE FROM `creature_addon` WHERE `guid` IN (
132567,
132568,
132566,
132564,
132565,
132553,
132554,
132555,
132556,
132557,
132558,
132559,
132560,
132561,
132562,
132563);
DELETE FROM `creature_template_addon` WHERE `entry`=23051;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(23051, 0, 0x0, 0x1, '');
