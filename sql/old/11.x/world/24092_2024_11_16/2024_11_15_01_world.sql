DELETE FROM `spell_proc` WHERE `SpellId` IN (387385);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(387385,0x00,5,0x00000000,0x00000040,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Backlash
