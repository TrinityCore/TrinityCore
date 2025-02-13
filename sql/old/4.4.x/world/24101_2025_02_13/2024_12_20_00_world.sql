DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_runic_empowerment';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81229, 'spell_dk_runic_empowerment');

DELETE FROM `spell_proc` WHERE `SpellId`= 81229;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(81229, 15, 0x0, 0x4 | 0x20000000, 0x1, 0x1, 0x2, 0x0);
