DELETE FROM `spell_proc` WHERE `SpellId`=64568;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(64568, 0, 0, 0, 0, 0, 0x100000, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `spell_bonus_data` SET `ap_bonus`=0, `ap_dot_bonus`=0 WHERE `entry`=64569;
