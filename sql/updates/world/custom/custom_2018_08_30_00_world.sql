DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dru_furor');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-17056, 'spell_dru_furor');

DELETE FROM `spell_proc` WHERE `SpellId`= -17056;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-17056, 7, 0x40000000 | 0x80000000, 0, 0, 0x00000800, 0, 0, 0, 0, 0, 0, 100);
