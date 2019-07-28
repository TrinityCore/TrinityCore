
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_unoly_blight';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49194, 'spell_dk_unoly_blight');

DELETE FROM `spell_proc` WHERE `SpellId`= 49194;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(49194 , 15, 0x00002000, 0, 0, 0, 1, 2, 0, 2);
