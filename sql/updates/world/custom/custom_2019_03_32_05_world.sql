SET @FAMILY_MASK_0 := 0 | 0x00000100 | 0x20000000 | 0x00000008 | 0x00010000;
SET @FAMILY_MASK_1 := 0 | 0x00000080 | 0x00000010;
SET @FAMILY_MASK_2 := 0 | 0x00008000;
SET @PROC_FLAGS := 0 | 0x00010000 | 0x00004000 | 0x00000400;

DELETE FROM `spell_proc` WHERE `SpellId`= 74434;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(74434, 5, @FAMILY_MASK_0, @FAMILY_MASK_1, @FAMILY_MASK_2, @PROC_FLAGS, 7, 1, 0, 0, 0, 1, 100);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warl_soulburn';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74434, 'spell_warl_soulburn');

UPDATE `spell_proc` SET `AttributesMask`= 16 | 32 WHERE `SpellId`= 27243;
