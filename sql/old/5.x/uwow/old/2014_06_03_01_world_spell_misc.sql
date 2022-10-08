delete from spell_script_names where ScriptName = 'spell_hun_thrill_of_the_hunt';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(2643, 'spell_hun_thrill_of_the_hunt'),
(3044, 'spell_hun_thrill_of_the_hunt');

delete from spell_proc_event where entry = 34720;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(34720, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 7);