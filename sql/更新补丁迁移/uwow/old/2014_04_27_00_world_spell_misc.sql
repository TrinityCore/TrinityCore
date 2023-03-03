delete from spell_proc_event where entry = 53651;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(53651, 0, 0, 0, 0, 0, 0, 559648, 0, 0, 100, 0, 7);

delete from spell_radius where spell_id = 53651;
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(53651, 51, 0, 0, 0, 0, '60 Yards');