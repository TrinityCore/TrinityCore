DELETE FROM `spell_proc` WHERE `SpellId`= -56333;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`, `Chance`) VALUES
(-56333, 9, 0, 0x08000000, 0x00020000 | 0x00004000, 0x00040000, 1, 2, 0, 0, 100);
