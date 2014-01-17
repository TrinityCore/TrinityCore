DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7636,7740) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7636,11,0,0,'achievement_bg_sa_defense_of_ancients'),
(7740,11,0,0,'achievement_bg_sa_defense_of_ancients');
