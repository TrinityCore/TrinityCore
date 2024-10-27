DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_wrath', 
'spell_dru_starfire', 
'spell_dru_starsurge',
'spell_dru_eclipse_solar',
'spell_dru_eclipse_lunar',
'spell_dru_eclipse_mastery_driver_passive');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(5176, 'spell_dru_wrath'),
(2912, 'spell_dru_starfire'),
(78674, 'spell_dru_starsurge'),
(48517, 'spell_dru_eclipse_solar'),
(48518, 'spell_dru_eclipse_lunar'),
(79577, 'spell_dru_eclipse_mastery_driver_passive');

DELETE FROM `spell_proc` WHERE `SpellId`= 79577;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(79577, 7, 0x1 | 0x4, 0x0, 0x2000000, 0x0, 0x1, 0x2);
