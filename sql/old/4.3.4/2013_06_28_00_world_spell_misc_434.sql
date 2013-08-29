DELETE FROM `spell_script_names` WHERE `spell_id` IN (34497,34498,34499);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(34497, 'spell_hun_thrill_of_the_hunt'),
(34498, 'spell_hun_thrill_of_the_hunt'),
(34499, 'spell_hun_thrill_of_the_hunt');

DELETE FROM `spell_proc_event` WHERE `entry` IN (34497,34498,34499);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(34497, 0, 9, 0x880, 0x88000000, 0, 0, 0, 0, 0, 0),
(34498, 0, 9, 0x880, 0x88000000, 0, 0, 0, 0, 0, 0),
(34499, 0, 9, 0x880, 0x88000000, 0, 0, 0, 0, 0, 0);
