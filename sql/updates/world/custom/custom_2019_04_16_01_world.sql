-- Infusion of Light
SET @FAMILY_FLAGS0 := 0 | 0x00200000;
SET @FAMILY_FLAGS1 := 0 | 0x00010000;
SET @FAMILY_FLAGS2 := 0 | 0x00010000;

DELETE FROM `spell_proc` WHERE `SpellId`= -53569;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-53569, 10, @FAMILY_FLAGS0, @FAMILY_FLAGS1, @FAMILY_FLAGS2, 0, 1 | 2, 2, 2, 2);

-- Seals of Command
SET @FAMILY_FLAGS0 := 0 | 0x20000000;
SET @FAMILY_FLAGS1 := 0 | 0x20000000;
SET @FAMILY_FLAGS2 := 0 | 0x00010000;

DELETE FROM `spell_proc` WHERE `SpellId`= 85126 ;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(85126 , 10, @FAMILY_FLAGS0, @FAMILY_FLAGS1, @FAMILY_FLAGS2, 0, 1, 1, 0, 2 | 32);

DELETE FROM `spell_bonus_data` WHERE `entry`= 101423;
INSERT INTO `spell_bonus_data` (`Entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(101423, 0, -1, 0, -1, 'Seal of Righteousness Dummy Proc AOE');
