DELETE FROM `spell_script_names` WHERE `spell_id`=-64127;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-64127,'spell_pri_body_and_soul');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=64127;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(64127, 64127, 1),
(64127, 64129, 2);

DELETE FROM `spell_proc_event` WHERE `entry` IN (64127,64129);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(64127, 0, 6, 0x1, 0x1, 0x80000, 0x4000, 0, 0, 100, 0),
(64129, 0, 6, 0x1, 0x1, 0x80000, 0x4000, 0, 0, 100, 0);
