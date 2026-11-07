DELETE FROM `spell_proc` WHERE `SpellId` IN (388812,392883);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(388812,0x00,53,0x00000000,0x02000080,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0), -- Vivacious Vivification
(392883,0x00,53,0x04000000,0x00000000,0x00000000,0x00040000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Vivacious Vivification
