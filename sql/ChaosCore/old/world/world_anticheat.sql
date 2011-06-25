REPLACE INTO `command` (`name`,`security`,`help`) VALUES ('anticheat global', '2', 'Syntax: .anticheat 
global returns the total amount reports and the average. (top three players)'), ('anticheat player', '2', 
'Syntax: .anticheat player $name returns the players''s total amount of warnings, the average and the 
amount of each cheat type.'), ('anticheat handle', '2', 'Syntax: .anticheat handle [on|off] Turn on/off the 
AntiCheat-Detection .'),
('anticheat delete', '2', 'Syntax: .anticheat delete [deleteall|$name] Deletes the report records of all the players or deletes all the reports of player $name.');
