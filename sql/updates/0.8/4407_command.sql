delete from command where name in('honor', 'honor add', 'honor addkill', 'honor flushkills','honor update', 'modify honor');

update `command` set `help` = 'Syntax: .modify $parameter $value\r\n\r\nModify the value of various parameters. Use .help modify $parameter to get help on specific parameter usage.\r\n\r\nSupported parameters include hp, mana, rage, energy, money, speed, swim, scale, bit, bwalk, aspeed, faction, spell, tp and honor.' where `name` = 'modify';

INSERT INTO `command` ( `name` , `security` , `help` ) VALUES 
('honor',2,'Syntax: .honor $command [$value] Various honor related commands. Use .help honor $command to get help on specific parameter usage. Supported parameters include add, addkill, flushkills, update'),
('honor add',2,'Syntax: .honor add $amount\r\n\r\nAdd a certain amount of honor (gained today) to the selected player.'),
('honor addkill',2,'Syntax: .honor addkikll\r\n\r\nAdd the targeted unit as one of your pvp kills today (you only get honor if it\'s a racial leader or a player)'),
('honor flushkills',2,'Syntax: .honor flushkills\r\n\r\nClear today\'s kills from the player limit storage (immediately) and from the DB (on next save) for the selected player.'),
('honor update',2,'Syntax: .honor update\r\n\r\nForce the yesterday\'s honor fields to be updated with today\'s data, which will get reset for the selected player.'),
('modify honor',1,'Syntax: .modify honor $amount\r\n\r\nAdded $amount to the selected player\'s total honor points.');