update creature_template set flags_extra = 536870913 where entry = 58632;

delete from spell_trigger_dummy where spell_id = 111394;

delete from spell_script_names where spell_id = 111394;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(111394, 'spell_blades_of_light');