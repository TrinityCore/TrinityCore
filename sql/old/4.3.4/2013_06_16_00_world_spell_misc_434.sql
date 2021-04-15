DELETE FROM `spell_script_names` WHERE `spell_id` IN (86183,86184,86185);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(86183, 'spell_sha_feedback'),
(86184, 'spell_sha_feedback'),
(86185, 'spell_sha_feedback');

DELETE FROM `spell_proc_event` WHERE `entry` IN (86183,86184,86185);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(86183, 0, 11, 0x3, 0, 0, 0, 0, 0, 0, 0),
(86184, 0, 11, 0x3, 0, 0, 0, 0, 0, 0, 0),
(86185, 0, 11, 0x3, 0, 0, 0, 0, 0, 0, 0);
