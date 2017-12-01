--
DELETE FROM `spell_proc` WHERE `SpellID`= 76838;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `AttributesMask`) VALUES
(76838, 4, 0, 0, 1, 1, 0x0000020);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_strikes_of_opportunity';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(76838, 'spell_warr_strikes_of_opportunity');
