DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_chakra',
'spell_pri_chakra_sanctuary',
'spell_pri_chakra_serenity_script',
'spell_pri_holy_word_sanctuary');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(14751, 'spell_pri_chakra'),
(81206, 'spell_pri_chakra_sanctuary'),
(81585, 'spell_pri_chakra_serenity_script'),
(88685, 'spell_pri_holy_word_sanctuary');

SET @FAMILYMASK0 := 0x00000400 | 0x00000800 | 0x00001000 | 0x00000200 | 0x00000080;
SET @FAMILYMASK1 := 0x00000004 | 0x00000020;
SET @FAMILYMASK2 := 0x00010000 | 0x00000000;

DELETE FROM `spell_proc` WHERE `SpellId` IN (14751, 88627);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(14751, 6, @FAMILYMASK0, @FAMILYMASK1, @FAMILYMASK2, 0, 2, 1, 0, 0, 0, 1, 100),
(88627, 0, 0x0, 0x0, 0x0, 0, 0, 1, 0, 16, 0, 0, 0);
