DELETE FROM `spell_proc` WHERE `SpellId`= 56414;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`) VALUES
(56414, 10, 0x4000, 0, 1, 2, 0, 0); -- Glyph of Dazing Shield

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warr_colossus_smash';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86346, 'spell_warr_colossus_smash');

UPDATE `spell_proc` SET `SpellFamilyMask0`= 0, `SpellFamilyMask1`= 0x1, `HitMask`= 0, `SpellTypeMask`= 1 WHERE `SpellId`= 58357; -- Glyph of Heroic Throw
