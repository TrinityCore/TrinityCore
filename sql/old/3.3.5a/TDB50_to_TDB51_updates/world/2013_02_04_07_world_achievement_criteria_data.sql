DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3931,12859,4227,3929);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
-- aliance
-- Kissed Sraaz
(3931,1,9099,0,''),
(3931,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(3931,15,3,0,''),
-- Handful of Rose Petals on Sraaz
(12859,1,9099,0,''),
(12859,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(12859,15,3,0,''),
-- horde
-- Kissed Jeremiah Payson
(3929,1,8403,0,''),
(3929,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(3929,15,3,0,''),
-- Handful of Rose Petals on Jeremiah Payson
(4227,1,8403,0,''),
(4227,11,0,0,'achievement_flirt_with_disaster_perf_check'),
(4227,15,3,0,'');
