-- Lightning Struck achievement move from criteria script to DB thx Vincent-Michael
DELETE FROM `achievement_criteria_data` WHERE `ScriptName`='achievement_lightning_struck';
DELETE FROM `achievement_criteria_data` WHERE `type`=7 AND `criteria_id`=6835;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6835, 7, 52092, 0, '');
