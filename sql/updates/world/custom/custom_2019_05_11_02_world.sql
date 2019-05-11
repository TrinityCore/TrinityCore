DELETE FROM `spell_proc` WHERE `SpellId`= 36032;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`) VALUES
(36032, 3, 0x00000800, 0x00008000, 0, 0, 1, 1, 0, 0, 0, 0);
