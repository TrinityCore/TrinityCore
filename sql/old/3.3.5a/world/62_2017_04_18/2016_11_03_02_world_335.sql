-- Maelstrom Weapon
DELETE FROM `spell_proc` WHERE `SpellId`=53817;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(53817, 0, 11, 0x000001C3, 0x00008000, 0x00000000, 0, 0x0, 0x1, 0x0, 0x8, 0, 0, 0, 0);
