DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` in (7625,6446,7628);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` in(6446,7625) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(6446,11,0,0,'achievement_bg_sa_drop_it'),
(7625,11,0,0,'achievement_bg_sa_artillery_veteran'),
(7628,11,0,0,'achievement_bg_sa_artillery_expert'),
(7628,3,607,0,'');
