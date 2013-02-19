DELETE FROM `disables` WHERE `entry` IN (12757,12954,12971,12978,12979,12980,13048,13059,13099,13124,13125,13126,13335,13355) AND `sourceType`=4;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12757,12954,12971,12978,12979,12980,13048,13059,13099,13124,13125,13126,13335,13355);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(12978,12,0,0,''),
(12979,12,1,0,''),
(12971,12,2,0,''),
(12980,12,3,0,''),
(12978,11,0,0,'achievement_portal_jockey'),
(12979,11,0,0,'achievement_portal_jockey'),
(12971,11,0,0,'achievement_portal_jockey'),
(12980,11,0,0,'achievement_portal_jockey'),
(13355,12,1,0,''),
(13335,12,0,0,''),
(12757,12,0,0,''),
(12954,12,1,0,''),
(13048,12,2,0,''),
(13059,12,3,0,''),
(13099,12,0,0,''),
(13125,12,2,0,''),
(13124,12,1,0,''),
(13126,12,3,0,'');
