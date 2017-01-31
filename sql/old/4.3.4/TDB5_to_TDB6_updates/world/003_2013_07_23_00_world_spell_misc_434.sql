DELETE FROM `spell_script_names` WHERE `spell_id`=-18119;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-18119,'spell_warl_improved_soul_fire');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=18119;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(18119, 18119, 1),
(18119, 18120, 2);

DELETE FROM `spell_proc_event` WHERE `entry` IN (18119,18120);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(18119, 0, 5, 0, 0x80, 0, 0x10000, 0, 0, 100, 0),
(18120, 0, 5, 0, 0x80, 0, 0x10000, 0, 0, 100, 0);
