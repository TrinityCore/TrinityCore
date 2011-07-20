DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` BETWEEN 10082 AND 10087;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` BETWEEN 10082 AND 10087 AND `type` IN (11,12);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10082,11,0,0,'achievement_i_choose_you'),
(10083,11,0,0,'achievement_i_choose_you'),
(10084,11,0,0,'achievement_i_choose_you'),
(10085,11,0,0,'achievement_i_choose_you'),
(10086,11,0,0,'achievement_i_choose_you'),
(10087,11,0,0,'achievement_i_choose_you'),
(10082,12,0,0,''),
(10083,12,0,0,''),
(10084,12,0,0,''),
(10085,12,1,0,''),
(10086,12,1,0,''),
(10087,12,1,0,'');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10088,10418,10419,10089,10420,10421);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10088,10418,10419,10089,10420,10421) AND `type` IN (11,12);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10088,11,0,0,'achievement_but_i_am_on_your_side'),
(10418,11,0,0,'achievement_but_i_am_on_your_side'),
(10419,11,0,0,'achievement_but_i_am_on_your_side'),
(10088,12,0,0,''),
(10418,12,0,0,''),
(10419,12,0,0,''),
(10089,11,0,0,'achievement_but_i_am_on_your_side'),
(10420,11,0,0,'achievement_but_i_am_on_your_side'),
(10421,11,0,0,'achievement_but_i_am_on_your_side'),
(10089,12,1,0,''),
(10420,12,1,0,''),
(10421,12,1,0,'');