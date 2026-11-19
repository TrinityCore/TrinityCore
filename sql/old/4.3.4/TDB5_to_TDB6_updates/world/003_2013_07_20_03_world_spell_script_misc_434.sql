DELETE FROM `spell_script_names` WHERE `spell_id`=56372;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(56372,'spell_mage_glyph_of_ice_block');

DELETE FROM `spell_proc_event` WHERE `entry`=56372;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56372, 0, 3, 0, 0x80, 0x8, 0x4000, 0, 0, 100, 0);
