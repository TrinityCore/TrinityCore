-- Add properly required fishing skill for Zul'Gurub area
DELETE FROM `skill_fishing_base_level` WHERE `entry`=1977;
INSERT INTO `skill_fishing_base_level` (`entry`, `skill`) VALUES
(1977, 330);
