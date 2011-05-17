-- Fix criteria for Wrath of the Horde achievements
DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry` IN (6637,6638,6639,6640);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (6637,6638,6639,6640);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6637,6,1537,0, ''), -- killed player in Ironforge
(6638,6,1657,0, ''), -- killed player in Darnassus
(6639,6,3557,0, ''), -- killed player in The Exodar
(6640,6,1519,0, ''); -- killed player in Stormwind City

-- Fix criteria for Wrath of the Alliance achievements
DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry` IN (6636,6633,6634,6635);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (6636,6633,6634,6635);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6636,6,1497,0, ''), -- killed player in Undercity
(6633,6,1638,0, ''), -- killed player in Thunder Bluff
(6634,6,3487,0, ''), -- killed player in Silvermoon City
(6635,6,1637,0, ''); -- killed player in Orgrimmar
