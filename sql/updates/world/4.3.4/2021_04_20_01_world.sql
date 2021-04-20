UPDATE `spell_proc` SET `SpellTypeMask`= `SpellTypeMask` | 0x2 WHERE `SpellId`= -20049;

DELETE FROM `spell_proc` WHERE `SpellId`= -53556;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `AttributesMask`) VALUES
(-53556, 10, 0x800000, 0x11110, 1, 4, 0x2);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_repentance';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20066, 'spell_pal_repentance');
