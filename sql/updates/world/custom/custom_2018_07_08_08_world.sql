DELETE FROM `spell_proc` WHERE `SpellId` IN (16257, 16277, 16278);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(16257, 0, 0, 0, 0, 0, 0, 0, 12287, 0, 0, 0, 100),
(16277, 0, 0, 0, 0, 0, 0, 0, 12287, 0, 0, 0, 100),
(16278, 0, 0, 0, 0, 0, 0, 0, 12287, 0, 0, 0, 100);
