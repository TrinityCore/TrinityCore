DELETE FROM `command` WHERE `name` IN ('reload spell_linked_spell');
INSERT INTO `command` VALUES
('reload spell_linked_spell','3','Usage: .reload spell_linked_spell\r\nReloads the spell_linked_spell DB table.');
