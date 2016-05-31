UPDATE `spell_dbc` SET `comment`='Freya Achievement spell - Criteria Marker' WHERE `id`=65074;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10445,10758) AND `type` IN (11,18);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10445,11,0,0,'achievement_getting_back_to_nature'),
(10758,11,0,0,'achievement_getting_back_to_nature');
