DELETE FROM `spell_proc` WHERE `SpellId` IN (77756);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(77756,0x00,11,0x10000000,0x00000000,0x00000000,0x00000000,0x40000,0x0,0x1,0x2,0x0,0x0,0x0,0,100,0,0); -- Lava Surge
