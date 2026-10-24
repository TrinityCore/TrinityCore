DELETE FROM `spell_proc` WHERE `SpellId` IN (51124);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(51124,0x10,15,0x00008080,0x00000000,0x00000000,0x00000000,0x10,0x0,0x1,0x4,0x0,0x12,0x0,0,0,0,0); -- Killing Machine
