DELETE FROM `spell_proc` WHERE `SpellId`= -93398;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`) VALUES
(-93398, 0x00000002 | 0x00200000, 0x0, 0x0, 0x00040000, 1, 2, 0, 0, 60000);
