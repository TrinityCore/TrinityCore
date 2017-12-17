DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_sha_elemental_overload';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77222, 'spell_sha_elemental_overload');

DELETE FROM `spell_proc` WHERE `SpellID`= 77222;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(77222, 11, 0, 0x00010000, 1, 2, 0, 0x0000020);
