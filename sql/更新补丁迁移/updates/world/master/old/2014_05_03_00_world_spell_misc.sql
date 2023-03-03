delete from spell_proc_event where entry = 146959;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(146959, 0, 10, 0, 0, 0, 0, 0, 2, 0, 0, 0, 7);

delete from spell_trigger where spell_id = 146959;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(146959, 148064, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Paladin - Glyph of Pillar of Light');