UPDATE `spell_bonus_data` SET `ap_bonus`= 0 WHERE `entry`= 12294;
DELETE FROM `spell_proc` WHERE `SpellId`= -84583;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-84583, 4, 0x02000000, 0, 1, 2, 0, 0);
