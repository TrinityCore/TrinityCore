DELETE FROM `spell_proc` WHERE `SpellId` IN (79684, 79683, 36032);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(79684, 3, 1, 2, 0, 40);

INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(79683, 3, 0x800, 0x1000, 5, 1, 0);

INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(36032, 3, 0x800, 0x8000, 0x1000 | 0x10000, 5, 1, 0);
