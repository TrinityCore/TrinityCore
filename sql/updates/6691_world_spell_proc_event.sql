-- Glyph of Seal of Command
DELETE FROM `spell_proc_event` WHERE `entry` IN (54925);
INSERT INTO `spell_proc_event`
(`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(54925,0x02,10,0x00000000,0x00000208,0x00000000,0x00000000,0x00000000,0,0,0);