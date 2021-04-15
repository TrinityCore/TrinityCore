-- Fix spell_proc_event for spell Arcane Blast, remove on Arcane Barrage or Arcane Explosion
DELETE FROM `spell_proc_event` WHERE `entry` = 36032;
INSERT INTO `spell_proc_event` (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
(36032, 0, 3, 0x1000, 0x8000, 0, 0, 0, 0, 0, 0);
