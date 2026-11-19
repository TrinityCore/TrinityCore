DELETE FROM `spell_proc` WHERE `SpellId` IN (451440,453329);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(451440,0x00,3,0x00000000,0x00000000,0x00000000,0x20000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0), -- Majesty of the Phoenix
(453329,0x00,3,0x00000004,0x00000000,0x00000000,0x00000000,0x0,0x0,0x5,0x4,0x0,0x0,0x0,0,0,0,0); -- Majesty of the Phoenix
