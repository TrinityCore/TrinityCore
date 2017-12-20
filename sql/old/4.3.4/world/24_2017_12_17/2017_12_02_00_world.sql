--
DELETE FROM `spell_proc` WHERE `SpellID`= 84722;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(84722 , 3, 0, 0x00010000, 0x00000004, 2, 0x00001000, 0);
