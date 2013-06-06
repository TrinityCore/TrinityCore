-- Criteria conditions for Once Bitten, Twice Shy achievement
DELETE FROM `achievement_criteria_data` WHERE `type`=12 AND `criteria_id` IN (13013, 13012, 13011, 12780);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`scriptname`) VALUES
(13013, 12, 1, 0, ""), -- heroic
(13012, 12, 1, 0, ""), -- heroic
(13011, 12, 0, 0, ""), -- normal
(12780, 12, 0, 0, ""); -- normal
