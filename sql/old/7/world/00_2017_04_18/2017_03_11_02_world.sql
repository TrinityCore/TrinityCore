DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_prismatic_barrier', 'spell_mage_blazing_barrier');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(235450, 'spell_mage_prismatic_barrier'),
(235313, 'spell_mage_blazing_barrier');

DELETE FROM `spell_proc_event` WHERE `entry` IN (11426, 235313);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `spellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(11426, 0, 3, 0, 0, 0, 0, 0, 1024, 0, 0, 0),
(235313, 0, 3, 0, 0, 0, 0, 0, 1024, 0, 0, 0);
