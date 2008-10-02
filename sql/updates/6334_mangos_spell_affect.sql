DELETE FROM spell_affect WHERE entry = 34491 AND effectId = 0 LIMIT 1;
DELETE FROM spell_affect WHERE entry = 34492 AND effectId = 0 LIMIT 1;
DELETE FROM spell_affect WHERE entry = 34493 AND effectId = 0 LIMIT 1;

INSERT INTO spell_affect ( entry , effectId , SpellFamilyMask ) VALUES
(34491, 0, 0x4000000000C2),
(34492, 0, 0x4000000000C2),
(34493, 0, 0x4000000000C2);