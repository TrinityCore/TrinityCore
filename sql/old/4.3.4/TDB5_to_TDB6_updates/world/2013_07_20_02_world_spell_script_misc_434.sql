DELETE FROM `spell_proc_event` WHERE `entry` IN (56342, 56343, 56333, 56336);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
-- Lock and Load
(56342, 0, 9, 0x18, 0, 0, 0x200000, 0, 0, 0, 0),
(56343, 0, 9, 0x18, 0, 0, 0x200000, 0, 0, 0, 0),
-- T.N.T.
(56333, 0, 9, 0x84, 0x8000000, 0x24000, 0x240000, 0, 0, 100, 0),
(56336, 0, 9, 0x84, 0x8000000, 0x24000, 0x240000, 0, 0, 100, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (-56333);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-56333,'spell_hun_tnt');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=56333;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(56333, 56333, 1),
(56333, 56336, 2);
