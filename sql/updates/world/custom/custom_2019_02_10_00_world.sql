UPDATE `spell_bonus_data` SET `ap_bonus`= 0, `ap_dot_bonus`= 0 WHERE `entry`= 22568;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dru_ferocious_bite',
'spell_rog_eviscerate');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22568, 'spell_dru_ferocious_bite'),
(2098, 'spell_rog_eviscerate');
