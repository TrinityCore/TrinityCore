--
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_hand_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76672 ,'spell_pal_hand_of_light');

DELETE FROM `spell_proc` WHERE `SpellID`= 76672;
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(76672 , 10, 0, 0x00000010, 1, 2, 0, 0x0000020);
