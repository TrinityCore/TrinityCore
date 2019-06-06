-- Show if player is online in lookup player commands
DELETE FROM `trinity_string` WHERE `entry` = '48';
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('48', '(online)');
UPDATE `trinity_string` SET `content_default` = '  %s (GUID %u) %s' WHERE (`entry` = '329');
