DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_eternal_flame', 'spell_pal_eternal_flame_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(156322, 'spell_pal_eternal_flame'),
(156322, 'spell_pal_eternal_flame_aura');
