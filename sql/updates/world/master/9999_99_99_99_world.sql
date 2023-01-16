DELETE FROM `spell_proc` WHERE `SpellId` IN (384667);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(384667,0x01,7,0x00000000,0x00000080,0x00200000,0x00001000,0x10,0x0,0x5,0x2,0x3,0x0,0x0,0,0,0,0); -- Sudden Ambush
