DELETE FROM trinity_string WHERE `entry` = 6616;
DELETE FROM `command` WHERE `name` IN ('reset all','reset talents');
INSERT INTO `command` VALUES
('reset all',3,'Syntax: .reset all spells\r\n\r\nSyntax: .reset all talents\r\n\r\nRequest reset spells or talents (including talents for all character\'s pets if any) at next login each existed character.'),
('reset talents',3,'Syntax: .reset talents [Playername]\r\n  Removes all talents of the targeted player or pet or named player. Playername can be name of offline character. With player talents also will be reset talents for all character\'s pets if any.');