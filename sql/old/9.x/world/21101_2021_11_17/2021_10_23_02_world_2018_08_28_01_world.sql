UPDATE `trinity_string` SET `entry`=5087 WHERE `entry`=5018;
DELETE FROM `trinity_string` WHERE `entry`=5018;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES (5018,"React state: %s");
