DELETE FROM `spell_script_names` WHERE `spell_id` IN (77794,77795,77796);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(77794, 'spell_sha_focused_insight'),
(77795, 'spell_sha_focused_insight'),
(77796, 'spell_sha_focused_insight');

DELETE FROM `spell_proc_event` WHERE `entry` IN (77794,77795,77796);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(77794, 0, 11, 0x90100000, 0, 0, 0, 0, 0, 0, 0),
(77795, 0, 11, 0x90100000, 0, 0, 0, 0, 0, 0, 0),
(77796, 0, 11, 0x90100000, 0, 0, 0, 0, 0, 0, 0);
