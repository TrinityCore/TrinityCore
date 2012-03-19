DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (7612,7613);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7612,7613);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7612,11,0,0, 'achievement_spore_loser'),
(7612,12,0,0,''),
(7613,11,0,0, 'achievement_spore_loser'),
(7613,12,1,0,'');
