DELETE FROM `spell_proc` WHERE `SpellId` IN (197125);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(197125,0x00,107,0x00000040,0x00000000,0x00000000,0x80000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Chaos Strike (Passive)
