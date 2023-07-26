DELETE FROM `spell_proc` WHERE `SpellId` IN (274902);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(274902,0x00,7,0x00000000,0x00000000,0x00000000,0x00400000,0x200000,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Photosynthesis

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_lifebloom', 'spell_dru_lifebloom_heal', 'spell_dru_photosynthesis', 'spell_dru_photosynthesis_effect');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(33763, 'spell_dru_lifebloom'),
(188550, 'spell_dru_lifebloom'),
(33778, 'spell_dru_lifebloom_heal'),
(274902, 'spell_dru_photosynthesis'),
(33763, 'spell_dru_photosynthesis_effect'),
(188550, 'spell_dru_photosynthesis_effect');
