DELETE FROM `spell_proc` WHERE `SpellId`= 52007;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(52007, 11, 0x00004400, 0x00000002, 0x00000002, 0, 20);
