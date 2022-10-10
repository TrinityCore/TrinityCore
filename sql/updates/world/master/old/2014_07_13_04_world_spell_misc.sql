delete from spell_linked_spell where spell_effect = 121186;
delete from spell_proc_event where entry = 58095;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(58095, 0, 4, 65536, 128, 0, 0, 0, 0, 0, 0, 0, 7);