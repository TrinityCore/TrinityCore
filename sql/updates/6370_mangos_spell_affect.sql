DELETE FROM spell_affect WHERE entry = 8875 AND effectId = 1 LIMIT 1;

INSERT INTO spell_affect ( entry , effectId , SpellFamilyMask ) VALUES
(8875, 1, 0x40000000000);
