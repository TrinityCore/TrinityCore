DELETE FROM `spell_proc` WHERE `SpellId` IN (393950,393951);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(393950,0x00,4,0x00000000,0x00000000,0x00000000,0x00000400,0x0,0x0,0x0,0x4,0x0,0x0,0x0,0,0,0,0), -- Bloodcraze
(393951,0x00,4,0x00000000,0x00000400,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x2,0x0,0x0,0,0,0,1); -- Bloodcraze
