DELETE FROM `disables` WHERE `entry` IN (7328,7329,7330,7331,7332,7333) AND `sourceType`=4;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7328,7329,7330,7331,7332,7333) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7328,11,0,0,'achievement_twilight_assist'),
(7329,11,0,0,'achievement_twilight_duo'),
(7330,11,0,0,'achievement_twilight_zone'),
(7331,11,0,0,'achievement_twilight_assist'),
(7332,11,0,0,'achievement_twilight_duo'),
(7333,11,0,0,'achievement_twilight_zone');
