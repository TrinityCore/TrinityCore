DELETE FROM `trinity_string` WHERE entry IN (80, 81);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES 
(80, 'BattleGround victories in the last 7 days\nAlliance: %d\nHorde: %d'),
(81, 'BattleGround scores storing is disabled!');

DELETE FROM `command` WHERE `name`='pvpstats';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('pvpstats', 797, 'Shows number of battleground victories in the last 7 days');
