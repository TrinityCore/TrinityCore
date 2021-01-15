DELETE FROM `spell_script_names` WHERE `spell_id` IN (82984,82988);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(82984, 'spell_sha_telluric_currents'),
(82988, 'spell_sha_telluric_currents');

DELETE FROM `spell_proc_event` WHERE `entry` IN (82984,82988);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(82984, 0, 11, 0x1, 0, 0, 0, 0, 0, 0, 0),
(82988, 0, 11, 0x1, 0, 0, 0, 0, 0, 0, 0);
