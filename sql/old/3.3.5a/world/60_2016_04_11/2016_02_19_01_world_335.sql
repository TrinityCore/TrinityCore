--
DELETE FROM `spell_proc_event` WHERE `entry`= 56841;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(56841, 0, 9, 0x800, 0x800, 0x800, 0x100, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hun_glyph_of_arcane_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56841,'spell_hun_glyph_of_arcane_shot');
