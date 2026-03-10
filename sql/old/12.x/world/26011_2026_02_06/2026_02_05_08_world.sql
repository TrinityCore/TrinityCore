DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dh_enduring_torment','spell_dh_enduring_torment_buff');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(452410, 'spell_dh_enduring_torment'),
(453314, 'spell_dh_enduring_torment_buff');
