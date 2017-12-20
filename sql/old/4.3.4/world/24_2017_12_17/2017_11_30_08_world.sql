--
DELETE FROM `spell_proc` WHERE `SpellID`= 76659;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `AttributesMask`) VALUES
(76659, 9, 0, 0, 1, 1, 0x0000020);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_wild_quiver';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76659, 'spell_hun_wild_quiver');
