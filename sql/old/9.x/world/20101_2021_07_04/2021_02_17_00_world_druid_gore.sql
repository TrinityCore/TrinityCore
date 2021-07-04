-- Attach druid's gore spell script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_gore';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(210706,'spell_dru_gore');

-- Override Gore spell proc flags
DELETE FROM `spell_proc` WHERE `SpellId` IN (210706,93622);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(210706,0,7,0x00200800,0x00100000,0x08000000,0x0,0,1,1,0x403,0,0,0,0,0,0),
(93622,0,7,0x0,0x40,0x0,0x0,0,1,2,0x403,0x8,0,0,0,0,0);
