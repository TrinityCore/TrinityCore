DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_lurk_search_check',
'spell_lurk_search',
'spell_feign_death',
'spell_lurk_ressurect',
'spell_lurk_search_victim',
'spell_vp_lurk_search',
'spell_vp_lurk_search_periodic',
'spell_vp_feign_death',
'spell_vp_lurk_ressurect');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85294, 'spell_vp_lurk_search_periodic'),
(85291, 'spell_vp_lurk_search'),
(86456, 'spell_vp_lurk_search'),
(86493, 'spell_vp_lurk_search'),
(85267, 'spell_vp_feign_death'),
(85281, 'spell_vp_lurk_ressurect');
