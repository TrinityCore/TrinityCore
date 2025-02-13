DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_steady_shot';
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 56641;

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56641, 'spell_hun_steady_shot');
