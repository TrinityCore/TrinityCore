DELETE FROM `spell_proc` WHERE `SpellId` IN (1265570);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1265570,0x01,4,0x00000000,0x08000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x403,0x0,0x0,0,0,0,0); -- Executioner's Wrath
