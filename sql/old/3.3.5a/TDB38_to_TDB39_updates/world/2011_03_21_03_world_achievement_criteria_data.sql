-- Fix Achievements related to Trial of the Crusader
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (
11684,11685,11686,11687,11688, -- 10 Player
11679,11680,11681,11682,11683, -- 25 Player
11689,11690,11691,11692,11693, -- 10 Player
11542,11546,11547,11549,11678  -- 25 Player
) AND `type` IN (0,12);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
-- Call of the Crusade (10 player)
(11684,12,0,0, ''),
(11685,12,0,0, ''),
(11686,12,0,0, ''),
(11687,12,0,0, ''),
(11688,12,0,0, ''),
-- Call of the Crusade (25 player)
(11679,12,1,0, ''),
(11680,12,1,0, ''),
(11681,12,1,0, ''),
(11682,12,1,0, ''),
(11683,12,1,0, ''),
-- Call of the Grand Crusade (10 player)
(11689,12,2,0, ''),
(11690,12,2,0, ''),
(11691,12,2,0, ''),
(11692,12,2,0, ''),
(11693,12,2,0, ''),
-- Call of the Grand Crusade (25 player)
(11542,12,3,0, ''),
(11546,12,3,0, ''),
(11547,12,3,0, ''),
(11549,12,3,0, ''),
(11678,12,3,0, '');
