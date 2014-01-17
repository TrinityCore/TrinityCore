DELETE FROM `command` WHERE `name` = 'pinfo';
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('pinfo','2','Syntax: .pinfo [$player_name/#GUID]\r\n\r\nOutput account information for selected player or player find by $player_name or #GUID.');
