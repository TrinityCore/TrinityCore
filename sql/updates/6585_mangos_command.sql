DELETE FROM command WHERE name = 'reload config';
INSERT INTO `command` VALUES
('reload config',3,'Syntax: .reload config\r\n\r\nReload config settings (by default stored in mangosd.conf). Not all settings can be change at reload: some new setting values will be ignored until restart, some values will applied with delay or only to new objects/maps, some values will explicitly rejected to change at reload.');
