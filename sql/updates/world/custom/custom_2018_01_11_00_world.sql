-- Warrior spell bonus datas
DELETE FROM `spell_bonus_data` WHERE `entry` IN (34428, 94009, 6343, 12294, 23881, 23922);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(34428, 0, 0, 0, 0, 'Warrior - Victory Rush'),
(94009, 0, 0, 0, 0, 'Warrior - Rend'),
(6343, 0, 0, 0.228, 0, 'Warrior - Thunder Clap'),
(12294, 0, 0, 0.236, 0, 'Warrior - Mortal Strike'),
(23881, 0, 0, -1, 0, 'Warrior - Bloodthirst'),
(23922, 0, 0, 0.6, 0, 'Warrior - Shield Slam');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warr_victory_rush',
 'spell_warr_victorious',
 'spell_warr_rend',
 'spell_warr_mortal_strike',
 'spell_gen_vengeance');
 
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(34428, 'spell_warr_victory_rush'),
(94009, 'spell_warr_rend'),
(93098, 'spell_gen_vengeance'),
(93099, 'spell_gen_vengeance'),
(84839, 'spell_gen_vengeance');
