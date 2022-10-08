update creature_template set flags_extra = 130 where entry = 29397;
update gameobject set spawntimesecs = 10 where id = 191502;

delete from spell_script_names where spell_id = 54355;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(54355, 'spell_gen_landmine_knockback');