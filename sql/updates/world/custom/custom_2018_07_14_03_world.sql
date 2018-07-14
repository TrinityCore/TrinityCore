DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_divine_purpose');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-85117, 'spell_pal_divine_purpose');

SET @FAMILY_FLAGS1 := 0 | 0x00800000;
SET @FAMILY_FLAGS2 := 0 | 0x00000002 | 0x00200000 | 0x00000080;
SET @FAMILY_FLAGS3 := 0 | 0x00002000 | 0x00008000;
SET @PROC_FLAGS    := 0 | 0x00000010 | 0x00000400| 0x00004000 | 0x00010000 | 0x00800000;

DELETE FROM `spell_proc` WHERE `SpellId` IN (-85117, 90174);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-85117, 10, @FAMILY_FLAGS1, @FAMILY_FLAGS2, @FAMILY_FLAGS3, @PROC_FLAGS, 7, 1, 0, 0, 0, 0, 100),
(90174, 10, 0, 0, 0, @PROC_FLAGS, 7, 1, 0, 8, 0, 1, 100);
