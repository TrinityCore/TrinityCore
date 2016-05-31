DELETE FROM `disables`WHERE `entry` IN(7631,7630,7629,6446,7625,7628,7626);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN(7631,7630,7629,6446,7625,7628,7626);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(7631,6,4609,0, ''),
(7630,6,4609,0, ''),
(7629,7,52418,0, ''),
(6446,7,52418,0, ''),
(7625,11,0,0, 'achievement_bg_sa_artillery'),
(7628,11,0,0, 'achievement_bg_sa_artillery');
