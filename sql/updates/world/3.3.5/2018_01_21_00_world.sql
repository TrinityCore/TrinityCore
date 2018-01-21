DELETE FROM `spell_bonus_data` WHERE `entry`=48210;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(48210, 0, 0, 0, 0, 'Warlock - Haunt heal');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_50pct_count_pct_from_max_hp' AND `spell_id`=48292;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dark_slash';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48292, 'spell_dark_slash');
