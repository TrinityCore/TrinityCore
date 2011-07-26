DELETE FROM `disables` WHERE `entry` IN (10088,10089,10418,10419,10420,10421);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10088,10089,10418,10419,10420,10421) AND `type`=5;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10088,5,58501,0,''),
(10089,5,58501,0,''),
(10418,5,58501,0,''),
(10419,5,58501,0,''),
(10420,5,58501,0,''),
(10421,5,58501,0,'');
