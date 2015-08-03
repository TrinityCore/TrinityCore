DELETE FROM `command` WHERE `name` IN ('reload item_set_names','reload locales_item_set_name');
INSERT INTO `command` VALUES
('reload item_set_names',3,'Syntax: .reload item_set_names\nReload item_set_names table.'),
('reload locales_item_set_name',3,'Syntax: .reload locales_item_set_name\nReload locales_item_set_name table.');
