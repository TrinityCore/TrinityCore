DELETE FROM `spell_script_names` WHERE (`spell_id`=361469 AND `ScriptName`='spell_evo_living_flame') OR (`spell_id`=361500 AND `ScriptName`='spell_evo_living_flame_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(361469, 'spell_evo_living_flame'),
(361500, 'spell_evo_living_flame_damage');
