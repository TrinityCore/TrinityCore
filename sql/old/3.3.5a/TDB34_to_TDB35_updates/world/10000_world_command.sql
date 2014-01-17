DELETE FROM `command` WHERE `name` IN ('ban character','ban playeraccount');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('ban character',3,'Syntax: .ban character $Name $bantime $reason\nBan character and kick player.\n$bantime: negative value leads to permban, otherwise use a timestring like "4d20h3s".'),
('ban playeraccount',3,'Syntax: .ban playeraccount $Name $bantime $reason\nBan account and kick player.\n$bantime: negative value leads to permban, otherwise use a timestring like "4d20h3s".');
