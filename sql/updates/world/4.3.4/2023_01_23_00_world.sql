DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_entangling_roots';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(339, 'spell_dru_entangling_roots');

DELETE FROM `spell_proc` WHERE `SpellId`= 339;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `Charges`) VALUES
(339, 0x1, 1);
