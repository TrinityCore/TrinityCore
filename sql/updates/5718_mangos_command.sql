DELETE FROM `command` WHERE `name` = 'modify rep';
DELETE FROM `command` WHERE `name` = 'modify arena';
DELETE FROM `command` WHERE `name` = 'lookup faction';

INSERT INTO `command` VALUES
('modify rep',2,'Syntax: .modify rep #repId (#repvalue | $rankname [#delta])\r\nSets the selected player\s reputation with faction #repId to #repvalue or to $reprank.\r\nIf the reputation rank name is provided, the resulting reputation will be the lowest reputation for that rank plus the delta amount, if specified.\r\nYou can use \'.pinfo rep\' to list all known reputation ids, or use \'.lookup faction $name\' to locate a specific faction id.'),
('modify arena',3,'Syntax: .modify arena #value\r\nSets the arena points to the #value (0-999999).'),
('lookup faction','3','Syntax: .lookup faction $name\r\nAttempts to find the ID of the faction with the provided $name.');
