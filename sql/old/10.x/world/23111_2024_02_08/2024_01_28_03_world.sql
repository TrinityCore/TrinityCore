DELETE FROM `spell_proc` WHERE `SpellId` IN (390676);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390676,0x02,6,0x00001C00,0x00818000,0x00000080,0x00000000,0x0,0x0,0x2,0x2,0x2,0x0,0x0,0,0,0,0); -- Inspiration
