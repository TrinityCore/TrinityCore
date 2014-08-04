DELETE FROM `spell_proc_event` WHERE `entry` IN (12950, 12329);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(-12329, 0, 4, 0, 4, 0, 4112, 0, 0, 0, 0);

DELETE FROM spell_script_names WHERE ScriptName = 'spell_warr_cleave';
INSERT INTO spell_script_names VALUES
(845, 'spell_warr_cleave');