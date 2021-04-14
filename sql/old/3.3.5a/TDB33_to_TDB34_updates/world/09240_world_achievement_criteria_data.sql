DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3693,6641,6642,6643,6644) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(3693,11,0,0, 'achievement_storm_glory'),
(6641,11,0,0, 'achievement_school_of_hard_knocks'),
(6642,11,0,0, 'achievement_school_of_hard_knocks'),
(6643,11,0,0, 'achievement_school_of_hard_knocks'),
(6644,11,0,0, 'achievement_school_of_hard_knocks');
