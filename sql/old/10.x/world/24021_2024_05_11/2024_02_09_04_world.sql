--
DELETE FROM `spell_proc` WHERE `SpellId` IN (390691);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390691,0x02,6,0x00000001,0x00000000,0x00000000,0x00000000,0x0,0x0,0x4,0x1,0x3,0x0,0x0,0,0,0,0); -- Borrowed Time
