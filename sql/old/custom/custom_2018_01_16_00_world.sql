DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_eclipse_mastery_driver_passive';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79577, 'spell_dru_eclipse_mastery_driver_passive');

DELETE FROM `spell_proc` WHERE `SpellID`= 79577;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(79577, 0, 0, 0x00010000, 1, 1);
