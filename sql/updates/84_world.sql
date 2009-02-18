DELETE FROM command WHERE name = 'reload all_locales';
INSERT INTO `command` VALUES
('reload all_locales',3,'Syntax: .reload all_locales\r\n\r\nReload all `locales_*` tables with reload support added and that can be _safe_ reloaded.');

