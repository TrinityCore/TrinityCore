DELETE FROM `disables` WHERE `entry`=7315 AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7315 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7315,11,0,0,'achievement_intense_cold');

DELETE FROM `spell_script_names` WHERE `spell_id`=48095;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)
VALUES
(48095,'spell_intense_cold');
