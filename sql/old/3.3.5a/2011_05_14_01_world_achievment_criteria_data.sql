DELETE FROM `disables` WHERE `entry` IN (7265,7549) AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7265,7549) AND `type` IN (0,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7265,11,0,0,'achievement_momma_said_knock_you_out'), -- Momma Said Knock You Out (10 player)
(7549,11,0,0,'achievement_momma_said_knock_you_out'); -- Momma Said Knock You Out (25 player)
