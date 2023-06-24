DELETE FROM `Kitron_string` WHERE `entry` IN (1202,1203,1204);
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES
(1202, 'Areatrigger debugging turned on.'),
(1203, 'Areatrigger debugging turned off.'),
(1204, 'You have reached areatrigger %u.');
