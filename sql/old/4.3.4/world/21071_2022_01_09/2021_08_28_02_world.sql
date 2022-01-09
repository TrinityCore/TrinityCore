DELETE FROM `spell_proc` WHERE `SpellId`= -63156;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-63156, 5, 0x1, 0x40 | 0x80, 0x1, 0x2);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warl_decimation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-63156, 'spell_warl_decimation');
