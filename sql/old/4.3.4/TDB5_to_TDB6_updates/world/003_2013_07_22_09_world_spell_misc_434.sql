DELETE FROM `spell_script_names` WHERE `spell_id`=54845;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(54845,'spell_dru_glyph_of_starfire_proc');

DELETE FROM `spell_proc_event` WHERE `entry`=54845;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(54845, 0, 7, 4, 0, 0, 65536, 0, 0, 100, 0);
