DELETE FROM `spell_proc` WHERE `SpellId` IN (12043,16166,17116);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(12043, 0, 3,  0x61400035, 0x00001000, 0x00000000, 0, 0x7, 0x1, 0x0, 0x8, 0, 0, 0, 0), -- Presence of Mind
(16166, 0, 11, 0x00000003, 0x00001000, 0x00000000, 0, 0x7, 0x1, 0x0, 0x8, 0, 0, 0, 0), -- Elemental Mastery
(17116, 0, 7,  0x10000261, 0x02000020, 0x00008000, 0, 0x7, 0x1, 0x0, 0x8, 0, 0, 0, 0); -- Nature's Swiftness
