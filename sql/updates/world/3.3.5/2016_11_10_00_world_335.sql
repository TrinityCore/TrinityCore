DELETE FROM `spell_proc` WHERE `SpellId` IN (-168, -7302, -30482);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-168,   0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x0, 0x0, 0x2, 0, 0, 0, 0), -- Frost Armor
(-7302,  0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x0, 0x0, 0x2, 0, 0, 0, 0), -- Ice Armor
(-30482, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x0, 0x0, 0x2, 0, 0, 0, 0); -- Molten Armor
