DELETE FROM `trinity_string` WHERE `entry` IN (300, 301);
INSERT INTO `trinity_string` (`entry`, `content_default`)VALUES
('300', 'Your chat has been disabled for %u minutes. Reason: %s.'),
('301', 'You have disabled %s\'s chat for %u minutes. Reason: %s.');

DELETE FROM `command` WHERE `name` = 'mute';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('mute', 1 ,'Syntax: .mute [$playerName] $timeInMinutes [$reason]\r\n\r\nDisible chat messaging for any character from account of character $playerName (or currently selected) at $timeInMinutes minutes. Player can be offline.');
