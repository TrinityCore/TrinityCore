DELETE FROM `spell_proc` WHERE `SpellId` IN (85739);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(85739,0x00,4,0x00300002,0x00202700,0x00000120,0x00900000,0x0,0x0,0x0,0x4,0x0,0x10,0x0,0,0,0,0); -- Whirlwind
