-- Pool quests from High Crusader Adelard
-- Source: http://www.wowwiki.com/High_Crusader_Adelard
SET @pool_id := 349;

-- create new pool, allowing only 1 out of 4 dailys per day
DELETE FROM `pool_template` WHERE `entry` = @pool_id;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id, 1, 'High Crusader Adelard - Daily Quests');

-- fill pools with the daily quests
DELETE FROM `pool_quest` WHERE `entry` IN (14101, 14102, 14104, 14105) AND `pool_entry` = @pool_id;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(14101, @pool_id, 'Drottinn Hrothgar'),
(14102, @pool_id, 'Mistcaller Yngvar'),
(14104, @pool_id, 'Ornolf The Scarred'),
(14105, @pool_id, 'Deathspeaker Kharos');
