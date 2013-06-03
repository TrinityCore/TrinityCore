SET @pool_id := 348;

DELETE FROM `pool_template` WHERE `entry` = @pool_id;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@pool_id, 1, 'Public Relations Agent <Crown Chemical Co.> - Daily Quests');

DELETE FROM `pool_quest` WHERE `entry` IN (24635, 24636, 24629) AND `pool_entry` = @pool_id;
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(24629, @pool_id, 'A Perfect Puff of Perfume'),
(24635, @pool_id, 'A Cloudlet of Classy Cologne'),
(24636, @pool_id, 'Bonbon Blitz');
