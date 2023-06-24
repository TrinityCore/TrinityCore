-- Show if player is online in lookup player commands
DELETE FROM `Kitron_string` WHERE `entry` = '48';
INSERT INTO `Kitron_string` (`entry`, `content_default`) VALUES ('48', '(online)');
UPDATE `Kitron_string` SET `content_default` = '  %s (GUID %u) %s' WHERE (`entry` = '329');
