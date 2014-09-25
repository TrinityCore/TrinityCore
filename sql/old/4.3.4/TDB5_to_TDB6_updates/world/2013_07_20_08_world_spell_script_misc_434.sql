DELETE FROM `spell_proc_event` WHERE `entry`=17619;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(17619, 0, 13, 0, 0, 0, 0x4800, 0, 0, 100, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`=17619;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(17619,'spell_gen_alchemist_stone');
