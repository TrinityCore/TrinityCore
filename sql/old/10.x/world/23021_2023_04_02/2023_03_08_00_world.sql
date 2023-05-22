DELETE FROM `spell_proc` WHERE `SpellId` IN (260286);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(260286,0x00,9,0x00000000,0x00000000,0x00010000,0x00000001,0x0,0x0,0x1,0x2,0x0,0x10,0x0,0,0,0,0); -- Tip of the Spear
