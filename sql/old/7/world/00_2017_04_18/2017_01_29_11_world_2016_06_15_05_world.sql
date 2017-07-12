--
DELETE FROM `skill_fishing_base_level` WHERE `entry` IN (4100,4987);
INSERT INTO `skill_fishing_base_level` (`entry`, `skill`) VALUES
(4987, 480),
(4100, 450);
