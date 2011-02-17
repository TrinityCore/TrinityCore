DELETE FROM `trinity_string` WHERE `entry` BETWEEN '11600' AND '11608';
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(11600, 'ChatSpy appended to player |cffff0000%s|r (GUID: %u).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ChatSpy подключён к игроку |cffff0000%s|r (GUID: %u).'),
(11601, 'ChatSpy for player |cffff0000%s|r (GUID: %u) cancelled by massive ChatSpy cancel.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ChatSpy был отключён от игрока |cffff0000%s|r (GUID: %u) массовым сбросом системы ChatSpy.'),
(11602, 'All ChatSpys reset.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Все цели ChatSpy обнулены.'),
(11603, 'Player %s (GUID: %u) has no ChatSpy.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'К игроку %s (GUID: %u) не прикреплён ChatSpy.'),
(11604, 'You were ChatSpying player, cancelled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Ваш ChatSpy был подключён к игроку... отменено.'),
(11605, '%s (GUID: %u) was ChatSpying player, cancelled.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, '%s (GUID: %u) установил ChatSpy на игрока, отменено.'),
(11606, 'List of ChatSpys appended.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Список подключённых систем ChatSpy.'),
(11607, 'Total: %u.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Всего: %u.'),
(11608, '%s (GUID: %u) spys |cffff0000%s|r (GUID: %u).', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'ChatSpy %s (GUID: %u) подключён к игроку |cffff0000%s|r (GUID: %u).');

SET @MAX_SEC := (SELECT MAX(security) FROM `command`);
DELETE FROM `command` WHERE `name` IN ('chatspy set', 'chatspy reset', 'chatspy status', 'chatspy cancel', 'chatspy mode');
INSERT INTO `command` VALUES
('chatspy set',    @MAX_SEC, 'Syntax: .chatspy set $PlayerName\r\n  Append ChatSpy on $player.'),
('chatspy reset',  @MAX_SEC, 'Syntax: .chatspy reset\r\n  Reset all ChatSpys.'),
('chatspy status', @MAX_SEC, 'Syntax: .chatspy status $PlayerName\r\n  Show ChatSpy status for $player.'),
('chatspy cancel', @MAX_SEC, 'Syntax: .chatspy cancel $PlayerName\r\n  Reset ChatSpy for $player.');
