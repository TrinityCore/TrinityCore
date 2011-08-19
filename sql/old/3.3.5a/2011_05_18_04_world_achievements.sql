-- Fix achievement criteria for Not In My House
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=7021;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7021;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7021,6,4572,0, ''), -- check if player is in Warsong Flag Room
(7021,7,23333,0, ''); -- check if victim has a Horde Flag buff
DELETE FROM `disables` WHERE `sourceType`=4 AND  `entry`=7020;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7020;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7020,6,4571,0, ''), -- check if player is in Silverwing Flag Room
(7020,7,23335,0, ''); -- check if victim has a Alliance Flag buff

-- Fix achievement criteria for Take a Chill Pill
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=3879;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=3879;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(3879,6,3820,0, ''), -- check if player is in Eye of the Storm
(3879,7,23505,0, ''); -- check if victim has a Berserking buff
