-- Strings for ASH + AFH allerts
DELETE FROM `trinity_string` where `entry` IN (6617, 6618, 6619, 6620, 6621, 6622, 6623, 6624, 6625);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6617', 'AntiCheat: SpeedHack Detected for %s, normal distance for this time and speed = %f, distance from packet = %f');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6618', 'AntiCheat: FlyHack Detected for %s , player can not fly');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6619', 'AntiCheat: FlyHack Detected for %s, player has Swimming flag, but not in water');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6620', 'AntiCheat: FlyHack Detected for %s');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6621', 'AntiCheat: DoubleJump Detected for %s');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6622', 'AntiCheat: Fake Jumper Detected for %s');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6623', 'AntiCheat: FakeFlying mode Detected for %s');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6624', 'AntiCheat: Wallclimb Detected for %s, diffZ = %f, distance = %f, angle = %f ');
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES ('6625', 'AntiCheat: Ignore controll Hack Detected for Account : %u, Player : %s');

-- Strings for Fake flying mode
DELETE FROM `trinity_string` where `entry` IN (884);
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES ('884', '│ CanFly ?: %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
