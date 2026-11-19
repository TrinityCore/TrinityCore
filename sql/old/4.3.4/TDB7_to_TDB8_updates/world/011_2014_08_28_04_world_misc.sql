-- .guild info command
DELETE FROM `command` WHERE `name`='guild info';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('guild info', 794, 'Shows information about target''''s guild or a given guild Id or Name.');

-- .guild info command strings
DELETE FROM `trinity_string` WHERE `entry` IN (1177,1178,1179,1180,1181,1182,1183);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1177, 'Displaying Guild Details for %s (Id: %u)'),
(1178, '| Guild Master: %s (GUID: %u)'),
(1179, '| Guild Creation Date: %s'),
(1180, '| Guild Members: %u'),
(1181, '| Guild Bank: %u gold'),
(1182, '| Guild MOTD: %s'),
(1183, '| Guild Information: %s');
