DELETE FROM `spell_proc` WHERE `SpellId` IN (369990,375583);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(369990,0x00,224,0x01000400,0x00000000,0x00000000,0x00000000,0x00000,0x0,0x4,0x1,0x0,0x0,0x0,0,0,0,0), -- Ancient Flame
(375583,0x00,224,0x00000000,0x00000000,0x00000000,0x00000000,0x14000,0x0,0x4,0x1,0x0,0x8,0x0,0,100,0,1); -- Ancient Flame
