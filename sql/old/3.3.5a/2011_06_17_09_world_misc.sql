-- Remove those achievements from disables table
DELETE FROM `disables` WHERE `entry` IN (10184,10243,10399,10400);

-- Achievement ScriptNames
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10184,10243,10399,10400) and `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10243,11,0,0,'achievement_nine_lives'),
(10399,11,0,0,'achievement_nine_lives'),
(10184,11,0,0,'achievement_crazy_cat_lady'),
(10400,11,0,0,'achievement_crazy_cat_lady');
