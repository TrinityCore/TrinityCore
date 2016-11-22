DELETE FROM `spell_script_names` WHERE `spell_id` = 203555;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('203555', 'spell_dh_demon_blades');
DELETE FROM `spell_proc_event` WHERE `entry` = 203555;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `spellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES ('203555', '0', '107', '0', '0', '0', '0', '4', '0', '0', '75', '0');

DELETE FROM `spell_proc_event` WHERE `entry`= 197125;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `spellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES('197125', '0', '107', '16448', '2048', '0', '0', '0', '2', '0', '0', '0');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (197125, 195072, 197923);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(197125, 'spell_dh_chaos_strike'),
(195072, 'spell_dh_fel_rush'),
(197923, 'spell_dh_fel_rush_aura');
