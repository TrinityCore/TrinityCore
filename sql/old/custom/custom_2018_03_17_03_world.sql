DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warl_fel_armor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28176, 'spell_warl_fel_armor');

DELETE FROM `spell_proc` WHERE `SpellId`= 28176;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(28176, 0x00050000, 0x00000001, 0x00000002, 0, 0x0000010 | 0x0000040);
