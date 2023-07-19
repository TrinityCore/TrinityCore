-- Divine Image
DELETE FROM `spell_proc` WHERE `SpellId` IN (392988);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392988,0x00,6,0x10000400,0x00000000,0x00000020,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Divine Image
