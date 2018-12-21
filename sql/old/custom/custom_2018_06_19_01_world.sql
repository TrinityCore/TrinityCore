DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_blood_rites';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(50034, 'spell_dk_blood_rites');

DELETE FROM `spell_proc` WHERE `spellId`= 50034;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(50034, 15, 0x00000010, 0x00020000, 0x0, 0x00015550, 0x1, 0x1, 0x0, 0x0);
