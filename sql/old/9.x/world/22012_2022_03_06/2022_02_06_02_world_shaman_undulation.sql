DELETE FROM `spell_proc` WHERE `SpellId` IN (200071,216251);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(200071,0x00,11,0x00000080,0x00000000,0x00010000,0x00000000,0x00004400,0x0,0x1,0x0,0x0,0x0,0,100,0,0), -- Undulation (passive)
(216251,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x8,0x0,0,0,0,0); -- Undulation (proc)

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_undulation_passive';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(200071,'spell_sha_undulation_passive');
