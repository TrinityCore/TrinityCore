DELETE FROM `spell_proc` WHERE `SpellId`= -14523;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-14523, 6, 0x00000080 | 0x00100000, 0, 0, 0x00010000, 1, 2, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_atonement',
'spell_pri_atonement_heal');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-14523, 'spell_pri_atonement'),
(81751, 'spell_pri_atonement_heal');
