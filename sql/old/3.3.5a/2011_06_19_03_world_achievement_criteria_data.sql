-- Fix achievement criteria for Supreme Defender
DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry`=3698;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3698;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(3698,6,3277,0, ''),  -- check if player is in Warsong Gulch
(3698,7,23333,0, '');  -- check if victim has a Horde Flag buff

DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry`=3699;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3699;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(3699,6,3277,0, ''),   -- check if player is in Warsong Gulch
(3699,7,23335,0, ''); -- check if victim has a Alliance Flag buff

-- Fix achievement criteria for Stormtrooper
DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry`=3685;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3685;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(3685,6,3820,0, ''), -- check if player is in EOTS
(3685,7,34976,0, '');  -- check if victim has a Netherstorm Flag buff
