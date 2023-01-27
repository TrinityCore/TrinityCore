delete from spell_bonus_data where entry = 85222;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `damage_bonus`, `heal_bonus`, `comments`) VALUES 
(85222, 0.152, 0, 0, 0, 0, 0, 'Paladin - Light of Dawn');

delete from spell_script_names where spell_id = 85222;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(85222, 'spell_pal_light_of_dawn');
