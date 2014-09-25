DELETE FROM `spell_script_names` WHERE `spell_id`=54832;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(54832,'spell_dru_glyph_of_innervate');

DELETE FROM `spell_proc_event` WHERE `entry`=54832;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(54832, 0, 7, 0, 4096, 0, 16384, 0, 0, 100, 0);
