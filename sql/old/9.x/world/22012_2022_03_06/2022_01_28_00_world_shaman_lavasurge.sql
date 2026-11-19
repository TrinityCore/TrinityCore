DELETE FROM `spell_proc` WHERE `SpellId` IN (77756,77762);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(77756,0x00,11,0x10000000,0x00000000,0x00000000,0x00000000,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Lava Surge (proc aura)
(77762,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x0,0x8,0x0,0,0,0,0); -- Lava Surge (effect buff)
