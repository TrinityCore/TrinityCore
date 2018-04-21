DELETE FROM `disables` WHERE `entry` IN (10173,10306,10451,10462) AND sourceType=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10173,10306,10451,10462) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10173,11,0,0,'achievement_shadowdodger'),
(10306,11,0,0,'achievement_shadowdodger'),
(10451,11,0,0,'achievement_smell_saronite'),
(10462,11,0,0,'achievement_smell_saronite');
