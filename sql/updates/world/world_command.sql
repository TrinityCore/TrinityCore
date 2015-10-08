DELETE FROM `command` WHERE `name`='reset arenaseason';
DELETE FROM `command` WHERE `name`='reset honorworld';

INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reset honorworld', 900, 'Syntax: .reset honorworld [kills]\nReset all honor points at the default values. With [kills] all the kills will be resetted.'),
('reset arenaseason', 901, 'Syntax: .reset arenaseason [delete]\nReset all rating and seasonGames/Wins, weekGames/Wins at the default values. With [delete] all teams will be deleted.');
