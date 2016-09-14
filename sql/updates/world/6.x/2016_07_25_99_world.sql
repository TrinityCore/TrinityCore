DELETE FROM `spell_script_names` WHERE `spell_id` = 203555;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('203555', 'spell_dh_demon_blades');
DELETE FROM `spell_proc_event` WHERE `entry` = 203555;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `spellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('203555', '0', '107', '0', '0', '0', '0', '4', '0', '0', '75', '0');
