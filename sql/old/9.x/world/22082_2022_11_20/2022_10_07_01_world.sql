--
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_rime';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(59057, 'spell_dk_rime');

DELETE FROM `spell_proc` WHERE `SpellId` IN (59057, 59052);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`, `DisableEffectsMask`, `Charges`) VALUES
(59057, 15, 0x8000 | 0x80, 0, 1, 1, 0x2, 0),
(59052, 15, 0x0, 0x2, 1, 1, 0, 1);
