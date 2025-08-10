DELETE FROM `spell_proc` WHERE `SpellId` IN (429020);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(429020,0x00,224,0x00400800,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x403,0x0,0x0,0,0,0,0); -- Fragile Echoes
