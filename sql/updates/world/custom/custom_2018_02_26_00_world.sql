DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_mage_hot_streak',
'spell_mage_improved_hot_streak',
'spell_mage_pyroblast');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44445, 'spell_mage_hot_streak'),
(-44446, 'spell_mage_improved_hot_streak'),
(92315, 'spell_mage_pyroblast');

DELETE FROM `spell_proc` WHERE `SpellID` IN (44445, -44446);
INSERT INTO `spell_proc` (`SpellID`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(44445, 3, 0, 0x00010000, 1, 2, 2, 0x0000020),
(-44446, 3, 0, 0x00010000, 1, 2, 0, 0x0000020);
