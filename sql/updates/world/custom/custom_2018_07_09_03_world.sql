DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_charkra',
'spell_pri_charkra_sanctuary',
'spell_pri_chakra_serenity');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(14751, 'spell_pri_charkra'),
(81206, 'spell_pri_charkra_sanctuary'),
(81585, 'spell_pri_chakra_serenity');

SET @FAMILYMASK0 := 0x00000400 | 0x00000800 | 0x00001000 | 0x00000200 | 0x00000080;
SET @FAMILYMASK1 := 0x00000004 | 0x00000020;
SET @FAMILYMASK2 := 0x00010000 | 0x00000000;

DELETE FROM `spell_proc` WHERE `SpellId`= 14751;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(14751, 6, @FAMILYMASK0, @FAMILYMASK1, @FAMILYMASK2, 0, 2, 1, 0, 0, 0, 1, 100);
