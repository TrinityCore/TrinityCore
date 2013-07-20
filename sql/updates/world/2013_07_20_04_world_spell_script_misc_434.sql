DELETE FROM `spell_script_names` WHERE `spell_id`=32216;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(32216,'spell_warr_victorious');

DELETE FROM `spell_proc_event` WHERE `entry`=32216;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(32216, 0, 4, 0, 256, 0, 16, 0, 0, 0, 0);
