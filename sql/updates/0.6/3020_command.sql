DELETE FROM `command` WHERE `name` = 'cooldown';
INSERT INTO command (name, security, help) VALUES ('cooldown', 3,'Syntax: .cooldown [#spell_id]\r\n\r\nRemove all (if spell_id not provided) or #spel_id spell cooldown from selected character or you (if no selection).');
