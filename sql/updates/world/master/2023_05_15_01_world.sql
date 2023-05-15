DELETE FROM `spell_proc` WHERE `SpellId` IN (384042);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(384042,0x00,4,0x00000000,0x00080000,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x0,0x0,0x0,0,0,0,0); -- Unnerving Focus
