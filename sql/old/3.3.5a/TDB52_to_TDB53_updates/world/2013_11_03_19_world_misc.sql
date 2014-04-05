--
DELETE FROM spell_scripts WHERE id=26373;
DELETE FROM spell_linked_spell WHERE spell_trigger=26373;
INSERT INTO spell_linked_spell VALUES (26373,26448,0,'Lunar Festival Invitation - Teleport Moonglade');
