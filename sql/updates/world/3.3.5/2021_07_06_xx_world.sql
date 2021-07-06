ALTER TABLE `waypoint_data` CHANGE `orientation` `orientation` FLOAT DEFAULT NULL NULL;
UPDATE `waypoint_data` SET `orientation`= NULL WHERE `orientation`= 0;
