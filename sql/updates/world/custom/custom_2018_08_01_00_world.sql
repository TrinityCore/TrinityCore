DELETE FROM `spell_proc` WHERE `SpellId`= 105765;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(105765, 10, 0x00800000, 0, 0x00000008, 0, 1, 1, 0, 0, 0, 0, 0);
