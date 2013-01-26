DELETE FROM `command` WHERE `name` LIKE 'pinfo';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('pinfo', '2', 'Syntax: .pinfo [$player_name/#GUID]\n\nOutput account and guild information for selected player or player find by $player_name or #GUID.');
