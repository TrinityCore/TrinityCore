-- Experienced Drake Rider Achiev

DELETE FROM `disables` WHERE `entry` IN (7177,7178,7179);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7177,7178,7179);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7177,5,49460,1,''),  -- Amber Drake
(7177,12,1,0, ''),    -- hc mode only
(7178,5,49346,1,''),  -- Emerald Drake
(7178,12,1,0, ''),    -- hc mode only
(7179,5,49464,1,''),  -- Ruby Drake
(7179,12,1,0, '');    -- hc mode only
