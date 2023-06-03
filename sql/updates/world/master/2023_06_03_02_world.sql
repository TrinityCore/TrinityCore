DELETE FROM `spell_proc` WHERE `SpellId` IN (391154,41635);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(391154,0x00,6,0x20000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x2,0x1,0x0,0x0,0,0,0,0), -- Holy Mending
(41635,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x0,0x0,0x0,0,0,0,0); -- Prayer of Mending
