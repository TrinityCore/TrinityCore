DELETE FROM `command` WHERE `name` LIKE 'lfg%';

INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lfg player', 2, 'Syntax: .lfg player\n Shows information about player (state, roles, comment, dungeons selected).'),
('lfg group', 2, 'Syntax: .lfg group\n Shows information about all players in the group  (state, roles, comment, dungeons selected).'),
('lfg queue', 2, 'Syntax: .lfg queue\n Shows info about current lfg queues.'),
('lfg clean', 3, 'Syntax: .flg clean\n Cleans current queue, only for debugging purposes.'),
('lfg options', 3, 'Syntax: .lfg options [new value]\n Shows current lfg options. New value is set if extra param is present.');