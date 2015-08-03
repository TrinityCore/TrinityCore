DELETE FROM `command` WHERE `name` IN ('reload creature_template');
INSERT INTO `command` VALUES
('reload creature_template','3','Syntax: .reload creature_template $entry\r\nReload the specified creature''s template.');
