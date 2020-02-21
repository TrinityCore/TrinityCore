DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_hun_focus_fire',
'spell_hun_frenzy_effect');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82692, 'spell_hun_focus_fire'),
(19615, 'spell_hun_frenzy_effect');
