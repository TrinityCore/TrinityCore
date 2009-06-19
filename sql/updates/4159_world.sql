DELETE FROM `trinity_string` WHERE `entry` BETWEEN 5012 AND 5019;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(5012, 'No maps found!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5013, '[Continent]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5014, '[Instance]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5015, '[Battleground]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5016, '[Arena]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5017, '[Raid reset time: %u]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5018, '[Heroic reset time: %u]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5019, '[Mountable]', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `command` WHERE `name` = 'lookup map';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lookup map', 3, 'Syntax: .lookup map $namepart\r\n\r\nLooks up a map by $namepart, and returns all matches with their map ID''s.');
