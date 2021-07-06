DELETE FROM `spell_proc` WHERE `SpellId`= 1776;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `Charges`) VALUES
(1776, 1, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_rog_gouge';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1776, 'spell_rog_gouge');
