DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_strength_of_soul',
'spell_pri_strength_of_soul_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-89488, 'spell_pri_strength_of_soul'),
(89490, 'spell_pri_strength_of_soul_script');

DELETE FROM `spell_proc` WHERE `SpellId`= -89488;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-89488, 6, 0x00000400 | 0x00001000 | 0x00000800, 0x40000000, 0, 0, 2 | 4, 2, 0, 0, 0, 0, 0);
