-- Icy Touch
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.2 WHERE `entry`= 45477;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_runic_empowerment';

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81229, 'spell_dk_runic_empowerment');
