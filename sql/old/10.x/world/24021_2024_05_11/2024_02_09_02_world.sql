DELETE FROM `spell_proc` WHERE `SpellId` IN (390786);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390786,0x02,6,0x00000000,0x00818000,0x00000000,0x00000000,0x0,0x0,0x3,0x2,0x3,0x0,0x0,0,0,0,0); -- Weal and Woe

DELETE FROM `spell_proc` WHERE `SpellId` IN (390787);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390787,0x02,6,0x00000081,0x00000000,0x00000000,0x00000000,0x0,0x0,0x5,0x1,0x3,0x0,0x0,0,0,0,1); -- Weal and Woe
