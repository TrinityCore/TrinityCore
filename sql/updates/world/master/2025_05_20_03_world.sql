DELETE FROM `spell_proc` WHERE `SpellId` IN (273946, 273947);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(273946,0x00,15,0x00040000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Hemostasis
(273947,0x00,15,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x8,0x0,0,0,0,1); -- Hemostasis
