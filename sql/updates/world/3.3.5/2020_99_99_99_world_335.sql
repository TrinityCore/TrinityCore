-- Use more appropriate name for distance used by random movement generator.
ALTER TABLE `creature`
	CHANGE COLUMN `spawndist` `wander_distance` FLOAT NOT NULL DEFAULT '0' AFTER `spawntimesecs`;

-- Update name used by chat command.
UPDATE `trinity_string` SET `content_default`='Wander distance changed to: %f' WHERE `entry`=297;
