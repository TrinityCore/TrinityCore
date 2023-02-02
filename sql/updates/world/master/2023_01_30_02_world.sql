-- Transfer the Power
DELETE FROM `spell_proc` WHERE `SpellId` IN (195300);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(195300,0x00,53,0x00000010,0x00000080,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,100,0,0); -- Transfer the Power
