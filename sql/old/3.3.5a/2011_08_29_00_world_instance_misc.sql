DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_putricide_expunged_gas';
DELETE FROM `spell_proc_event` WHERE `entry` IN (70215,72858,72859,72860,70672,72455,72832,72833);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(70672,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0),
(72455,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0),
(72832,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0),
(72833,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0);
