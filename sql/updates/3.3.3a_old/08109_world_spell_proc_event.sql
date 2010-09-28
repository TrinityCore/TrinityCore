-- Arcane Empowerment proc event
DELETE FROM spell_proc_event WHERE entry IN (31583, 31582, 31579);
INSERT INTO spell_proc_event (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
(31583,0,3,0x20201000,0x8000,0x0,0x00010000,0x0000002,0,0,0),
(31582,0,3,0x20201000,0x8000,0x0,0x00010000,0x0000002,0,0,0),
(31579,0,3,0x20201000,0x8000,0x0,0x00010000,0x0000002,0,0,0);
