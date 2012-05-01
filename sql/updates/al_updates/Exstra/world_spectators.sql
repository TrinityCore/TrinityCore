DELETE FROM `trinity_string` WHERE `entry` BETWEEN '11610' AND '11615';
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES
('11610', 'Player %s forbided you to watch his arena match.', 'Игрок %s не желает чтобы Вы были зрителем его боя на арене.'),
('11611', 'Player %s is not a member of arena match.', 'Игрок %s не на арене.'),
('11612', 'You should not be a member of arena or battleground match.', 'Вы не можете стать зрителем, находясь на поле боя или арене.'),
('11613', 'You already have a spectator state.', 'Вы уже являетесь зрителем.'),
('11614', 'Arena spectators system disabled.', 'Система зрителей на арене отключена.'),
('11615', 'You cannot use chat while you are a spectator.', 'Находясь в режиме зрителя, вы не можете пользоваться чатом.');

DELETE FROM `command ` WHERE `name` = 'spectate player';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('spectate player', 0, 'Syntax: .spectate player $player\r\n\r\nДелает вас зрителем боев на арене с $player');