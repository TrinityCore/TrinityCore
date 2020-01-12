-- Strings for ASH + AFH allerts
DELETE FROM `trinity_string` where `entry` IN (884, 6617, 6618, 6619, 6620, 6621, 6622, 6623, 6624, 6625, 6626);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
('884', '│ CanFly ?: %s'),
('6617', 'AntiCheat: SpeedHack Detected for %s, normal distance for this time and speed = %f, distance from packet = %f'),
('6618', 'AntiCheat: FlyHack Detected for %s , player can not fly'),
('6619', 'AntiCheat: FlyHack Detected for %s, player has Swimming flag, but not in water'),
('6620', 'AntiCheat: FlyHack Detected for %s'),
('6621', 'AntiCheat: DoubleJump Detected for %s'),
('6622', 'AntiCheat: Fake Jumper Detected for %s'),
('6623', 'AntiCheat: FakeFlying mode Detected for %s'),
('6624', 'AntiCheat: Wallclimb Detected for Account id : %u, Player %s, diffZ = %f, distance = %f, angle = %f, Map = %s, mapId = %u, X = %f, Y = %f, Z = %f'),
('6625', 'AntiCheat: Ignore control Hack Detected for Account : %u, Player : %s'),
('6626', 'AntiCheat: NoFallingDamage Hack Detected for Account : %u, Player : %s');
