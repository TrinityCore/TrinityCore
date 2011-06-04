DELETE FROM `command` WHERE `name` IN ('baninfo playeraccount', 'banlist playeraccount');
INSERT INTO `command` VALUES
('baninfo playeraccount', 3, 'Syntax: .baninfo playeraccount $playerName\r\nWatch full information about a specific ban.'),
('banlist playeraccount', 3, 'Syntax: .banlist playeraccount [$Name]\r\nSearches the banlist for accounts according to a character name pattern.');