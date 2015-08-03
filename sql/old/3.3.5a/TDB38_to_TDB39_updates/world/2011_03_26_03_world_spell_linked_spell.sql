-- Spell Arcane Barrage
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=56397;
INSERT INTO `spell_linked_spell` (spell_trigger,spell_effect,type,comment) VALUES (56397,63934,1,'Arcane Barrage - Arcane Barrage');
