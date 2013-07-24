DELETE FROM `spell_script_names` WHERE `spell_id`=56374;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(56374,'spell_mage_glyph_of_icy_veins');

DELETE FROM `spell_proc_event` WHERE `entry`=56374;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56374, 0, 3, 0, 16384, 0, 16384, 0, 0, 100, 0);
