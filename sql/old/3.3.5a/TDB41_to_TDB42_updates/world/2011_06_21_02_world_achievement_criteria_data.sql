DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10068,10069) AND `type` IN (0,11);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10068,11,0,0,'achievement_ignis_shattered'), -- Shattered (10 Player)
(10069,11,0,0,'achievement_ignis_shattered'); -- Shattered (25 Player)
