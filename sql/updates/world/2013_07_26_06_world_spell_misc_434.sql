DELETE FROM `spell_proc_event` WHERE `entry`IN (-78892,-81021);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(-78892, 0, 7, 0, 0, 0x30, 0x1000, 0, 0, 100, 0),
(-81021, 0, 0, 0, 0, 0, 0x10, 0, 0, 100, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`=-78892;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-78892,'spell_dru_stampede');

DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (81016,81021);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
-- Bear
(81016, 81016, 1),
(81016, 81017, 2),
-- Cat
(81021, 81021, 1),
(81021, 81022, 2);
