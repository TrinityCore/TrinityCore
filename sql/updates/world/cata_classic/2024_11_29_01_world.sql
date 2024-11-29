DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_cobra_shot';
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 77767;

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77767, 'spell_hun_cobra_shot');
