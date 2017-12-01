--
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pri_echo_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77485, 'spell_pri_echo_of_light');

DELETE FROM `spell_proc` WHERE `SpellID`= 77485;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(77485, 6, 0, 0x00004000, 2, 2, 0, 0x0000020);
