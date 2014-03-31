DELETE FROM `spell_script_names` WHERE `scriptName` = 'spell_cultist_dark_martyrdom';
DELETE FROM `spell_script_names` WHERE `spell_id` = '57591';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('57591', 'spell_lava_strike');
DELETE FROM `disables` WHERE `sourceType` = '4' AND `entry` = '7327';
DELETE FROM `disables` WHERE `sourceType` = '4' AND `entry` = '7326';
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = '7326';
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = '7327';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `ScriptName`) VALUES
('7326', '11', '0', 'achievement_gonna_go_when_the_vulcano_blows'),
('7326', '12', '0', ''),
('7327', '11', '0', 'achievement_gonna_go_when_the_vulcano_blows'),
('7327', '12', '1', '');
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7740 AND `type` = 0;
DELETE FROM `achievement_criteria_data`WHERE `criteria_id` = '7636' AND `type` = '0';
