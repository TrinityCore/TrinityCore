--
DELETE FROM `trinity_string` WHERE `entry` IN (10056,10057);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(10056, "Characters below level 10 are not eligible for faction change."),
(10057, "Death Knights below level 60 are not eligible for faction change.");
