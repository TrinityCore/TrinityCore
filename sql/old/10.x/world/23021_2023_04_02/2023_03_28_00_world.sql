DELETE FROM `spell_proc` WHERE `SpellId` IN (388106,389763,391189);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(388106,0x00,107,0x00000020,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0), -- Soulrend
(389763,0x00,107,0x00000020,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0), -- Master of the Glaive
(391189,0x00,107,0x00000021,0x00001000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Burning Wound
