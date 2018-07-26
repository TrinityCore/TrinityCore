UPDATE `spell_proc` SET `HitMask`= 0 WHERE `SpellId`= -16487;

DELETE FROM `spell_proc` WHERE `SpellId`= -50685;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-50685, 4, 0x00000040, 0, 0, 0, 1, 2, 2, 0, 0, 0, 0);
