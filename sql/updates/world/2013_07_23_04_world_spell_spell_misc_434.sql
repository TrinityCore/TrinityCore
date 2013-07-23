DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pal_blessing_of_sanctuary';

DELETE FROM `spell_proc_event` WHERE `entry` IN (20911,84628,84629);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(20911, 0, 0, 0, 0, 0, 0, 0x50, 0, 0, 0),
(84628, 0, 0, 0, 0, 0, 0, 0x50, 0, 0, 0),
(84629, 0, 0, 0, 0, 0, 0, 0x50, 0, 0, 0),
