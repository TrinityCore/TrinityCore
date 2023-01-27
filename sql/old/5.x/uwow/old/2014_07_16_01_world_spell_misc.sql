delete from spell_proc_event where entry = 138301;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(138301, 0, 6, 268435456, 65536, 0, 0, 0, 0, 0, 0, 3, 7);

delete from spell_script_names where ScriptName = 'spell_pri_t15_healer_4p';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (138302, 'spell_pri_t15_healer_4p');