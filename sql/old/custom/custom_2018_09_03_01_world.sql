DELETE FROM `spell_proc` WHERE `SpellId` IN (83074, 44544, 57761);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(83074, 3, 1049120, 4096, 0, 0, 0, 2, 0, 2, 0, 0, 25),
(44544, 3, 0x00020000, 0x00100000, 0, 0x00010000, 1, 1, 0, 0, 0, 1, 100),
(57761, 3, 0x00000001, 0x00001000, 0, 0x00010000, 1, 1, 0, 0, 0, 1, 100);

UPDATE `spell_proc` SET `SpellPhaseMask`= 2 WHERE `SpellId` IN (44543, 44545);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_deep_freeze';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44572, 'spell_mage_deep_freeze');
