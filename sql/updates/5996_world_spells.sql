-- Fix spell_proc_event for spell Arcane Blast, remove on Arcane Barrage or Arcane Explosion
DELETE FROM `spell_proc_event` WHERE `entry` = 36032;
INSERT INTO `spell_proc_event` (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
(36032, 0, 3, 0x1000, 0x8000, 0, 0, 0, 0, 0, 0);
-- Fix removing of Arcane Blast buff caused by Arcane Missiles spell
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-5143, -5144, -5145, -8416, -8417, -10211, -10212, -25345, -27075, -38699, -38704, -42843, -42846) AND `spell_effect` = -36032;
INSERT INTO `spell_linked_spell` (spell_trigger, spell_effect, type, comment) VALUES
(-5143, -36032, 0, 'Arcane Missiles Rank 1'),
(-5144, -36032, 0, 'Arcane Missiles Rank 2'),
(-5145, -36032, 0, 'Arcane Missiles Rank 3'),
(-8416, -36032, 0, 'Arcane Missiles Rank 4'),
(-8417, -36032, 0, 'Arcane Missiles Rank 5'),
(-10211, -36032, 0, 'Arcane Missiles Rank 6'),
(-10212, -36032, 0, 'Arcane Missiles Rank 7'),
(-25345, -36032, 0, 'Arcane Missiles Rank 8'),
(-27075, -36032, 0, 'Arcane Missiles Rank 9'),
(-38699, -36032, 0, 'Arcane Missiles Rank 10'),
(-38704, -36032, 0, 'Arcane Missiles Rank 11'),
(-42843, -36032, 0, 'Arcane Missiles Rank 12'),
(-42846, -36032, 0, 'Arcane Missiles Rank 13');