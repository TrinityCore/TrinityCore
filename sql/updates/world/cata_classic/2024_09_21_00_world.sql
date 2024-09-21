DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_deep_freeze_immunity_state';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71761, 'spell_mage_deep_freeze_immunity_state');

DELETE FROM `spell_proc` WHERE `SpellId`= 71761;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask1`, `SpellTypeMask`, `HitMask`, `SpellPhaseMask`) VALUES
(71761, 3, 0x100000, 0x4, 0x100, 0x2);
