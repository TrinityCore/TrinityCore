DELETE FROM `spell_proc_event` WHERE `entry` IN (34485,34486,34487,82926);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(34485, 0, 9, 0, 0x1, 0, 0, 0, 0, 0, 0),
(34486, 0, 9, 0, 0x1, 0, 0, 0, 0, 0, 0),
(34487, 0, 9, 0, 0x1, 0, 0, 0, 0, 0, 0),
(82926, 0, 9, 0x20000, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`IN (82925,82926);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(82925,'spell_hun_ready_set_aim'),
(82926,'spell_hun_fire');
