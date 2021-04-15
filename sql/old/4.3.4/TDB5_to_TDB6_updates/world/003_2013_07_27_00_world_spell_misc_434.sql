DELETE FROM `spell_proc_event` WHERE `entry`=-84583;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(-84583, 0, 4, 0x2000000, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`=-84583;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-84583,'spell_warr_lambs_to_the_slaughter');
