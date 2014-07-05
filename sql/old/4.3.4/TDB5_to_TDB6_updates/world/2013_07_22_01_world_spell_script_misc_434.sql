DELETE FROM `spell_script_names` WHERE `spell_id`=58387;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(58387,'spell_warr_glyph_of_sunder_armor');

DELETE FROM `spell_proc_event` WHERE `entry`=58387;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(58387, 0, 4, 16384, 64, 0, 16, 0, 0, 100, 0);
