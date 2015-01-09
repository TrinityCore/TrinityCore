DELETE FROM `spell_script_names` WHERE `spell_id`=56375;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(56375,'spell_mage_glyph_of_polymorph');

DELETE FROM `spell_proc_event` WHERE `entry`=56375;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56375, 0, 3, 16777216, 0, 0, 65536, 0, 0, 100, 0);
