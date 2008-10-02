DELETE FROM `command`  WHERE `name` = 'modify level';

UPDATE `command` SET `help` = 'Syntax: .die\r\n\r\nKill the selected player or creature. If no player or creature selected, it will kill you.' WHERE `name` = 'die';

