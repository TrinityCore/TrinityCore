--
DELETE FROM `trinity_string` WHERE `entry` IN (395, 396);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(395, '### USAGE: .bg start
Skips battleground preparation time and starts the battle.'),
(396, '### USAGE: .bg stop
Immediately ends the battleground.');
