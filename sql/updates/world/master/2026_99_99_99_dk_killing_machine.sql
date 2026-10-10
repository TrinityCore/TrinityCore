DELETE FROM `spell_proc` WHERE `SpellId` IN (51124);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(51124,0x00,15,0x00008000,0x00020000,0x00000000,0x00000000,0x10000,0x4,0x1,0x1,0x0,0x10,0x0,0,100,0,0); -- Killing Machine
