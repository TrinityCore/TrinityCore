--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_gen_knock_away_threat_reduction_100',
'spell_gen_knock_away_threat_reduction_50',
'spell_gen_knock_away_threat_reduction_25');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(10101, 'spell_gen_knock_away_threat_reduction_100'),
(18670, 'spell_gen_knock_away_threat_reduction_50'),
(18945, 'spell_gen_knock_away_threat_reduction_50'),
(18813, 'spell_gen_knock_away_threat_reduction_25'),
(25778, 'spell_gen_knock_away_threat_reduction_25');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_revive_self';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32343, 'spell_gen_revive_self');
