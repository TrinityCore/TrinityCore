DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pet_ghoul_dummy_ability',
'spell_dk_shadow_infusion',
'spell_dk_dark_transformation',
'spell_dk_dark_transformation_aura');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47481, 'spell_pet_ghoul_dummy_ability'),
(47482, 'spell_pet_ghoul_dummy_ability'),
(47468, 'spell_pet_ghoul_dummy_ability'),
(47484, 'spell_pet_ghoul_dummy_ability'),
(-48965, 'spell_dk_shadow_infusion'),
(63560, 'spell_dk_dark_transformation'),
(93426, 'spell_dk_dark_transformation_aura');

DELETE FROM `spell_proc` WHERE `SpellId`= -48965;
INSERT INTO `spell_proc` (`SpellID`, `SchoolMask`, `SpellFamilyName`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-48965, 32, 15, 0x00010000 | 0x00004000, 7, 1, 12287);
