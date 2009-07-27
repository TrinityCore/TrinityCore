UPDATE `trinity_string` SET `content_default` = 'Active connections: %u (max: %u) Queued connections: %u (max: %u)' WHERE `entry` = 12;

DELETE FROM `trinity_string` WHERE `entry` = 60;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES (60, 'Online players: %u (max: %u)');