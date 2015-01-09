DELETE FROM `spell_script_names` WHERE `spell_id` IN (50240,49840,49592);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50240, 'spell_oculus_evasive_maneuvers'),
(49840, 'spell_oculus_shock_lance'),
(49592, 'spell_oculus_temporal_rift');

DELETE FROM `spell_proc_event` WHERE `entry` IN (49592,50240);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(49592,0,0,0,0,0,0x008222A8,0,0,0,0),
(50240,0,0,0,0,0,0,0x14,0,0,0);
