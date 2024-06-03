DELETE FROM `spell_proc` WHERE `SpellId` IN (44401);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(44401,0x00,3,0x00000000,0x00000000,0x00000000,0x11000,0x5,0x1,0x0,0x8,0x0,0,0,0,1); -- Missile Barrage
