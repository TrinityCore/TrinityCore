-- Add skill_fishing_base_level -20 to Undercity, based on other capital cities
DELETE FROM `skill_fishing_base_level` WHERE `entry`=1497;
INSERT INTO `skill_fishing_base_level` (`entry`, `skill`) VALUES
(1497, -20);
