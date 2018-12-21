DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pri_holy_word_sanctuary_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88686, 'spell_pri_holy_word_sanctuary_triggered');

DELETE FROM `spell_proc` WHERE `SpellId`= 88688;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(88688, 6, 0x00000800, 0x0, 0x0, 0x00004000, 1, 1, 0, 0, 0, 1, 100);
