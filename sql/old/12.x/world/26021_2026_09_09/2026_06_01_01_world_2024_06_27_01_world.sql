--
DELETE FROM `trinity_string` WHERE `entry` IN (397,398);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(397, "Characters below level 10 are not eligible for faction change."),
(398, "Death Knights below level 60 are not eligible for faction change.");
