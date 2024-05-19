--
DELETE FROM `spell_proc` WHERE `SpellId` IN (198068);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(198068,0x24,6,0x00008000,0x00000000,0x00000000,0x00000010,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Power of the Dark Side
