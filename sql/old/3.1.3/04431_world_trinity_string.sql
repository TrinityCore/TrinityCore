UPDATE `Kitron_string` SET `content_default` = 'Active connections: %u (max: %u) Queued connections: %u (max: %u)' WHERE `entry` = 12;

DELETE FROM `Kitron_string` WHERE `entry` = 60;
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES (60, 'Online players: %u (max: %u)');
