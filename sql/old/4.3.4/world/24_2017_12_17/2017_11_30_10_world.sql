--
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_illuminated_healing';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76669, 'spell_pal_illuminated_healing');

DELETE FROM `spell_proc` WHERE `SpellID`= 76669;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(76669, 10, 0, 0x00004000, 2, 2, 0, 0x0000020);
