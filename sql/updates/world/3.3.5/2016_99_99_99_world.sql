SET @ENTRY := 2031;
DELETE FROM `trinity_string` WHERE `entry` BETWEEN @ENTRY AND @ENTRY+14;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@ENTRY+0,  'The anticheat system has reported that you may be cheating. You will be monitored to confirm if this is accurate.'),
(@ENTRY+1,  'The anticheat system is disabled.'),
(@ENTRY+2,  'The anticheat system is now enabled!'),
(@ENTRY+3,  'The anticheat system is now disabled!'),
(@ENTRY+4,  'Information about player %s'),
(@ENTRY+5,  'Average: %f || Total Reports: %u'),
(@ENTRY+6,  'Speed Reports: %u || Fly Reports: %u || Jump Reports: %u'),
(@ENTRY+7,  'Walk on Water Reports: %u || Teleport to Plane Reports: %u'),
(@ENTRY+8,  'Climb Reports: %u'),
(@ENTRY+9,  '|cFFFFFC00[AC] |cffffffff|Hplayer:%s|h[%s]|h|r|cFF00FFFF Possible cheater!|r'),
(@ENTRY+10, '============================='),
(@ENTRY+11, 'Players with the lowest averages:'),
(@ENTRY+12, 'Player: %s Average: %f Total Reports: %u'),
(@ENTRY+13, 'Players with the most reports:'),
(@ENTRY+14, 'Player: %s Total Reports: %u Average: %f');

DELETE FROM `command` WHERE `permission` BETWEEN 837 AND 842;
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('anticheat', 845, 'Syntax: .anticheat $subcommand\nType .anticheat to see the list of possible subcommands or .help anticheat $subcommand to see info on subcommands'),
('anticheat global', 846, 'Syntax: .anticheat global\n\nShows top 3 global anticheat stadistics'),
('anticheat player', 847, 'Syntax: .anticheat player [$name]\n\nShows anticheat stadistics for player $name or selected player if not provided'),
('anticheat handle', 848, 'Syntax: .anticheat handle on|off\n\nEnables/disables AC system'),
('anticheat jail', 849, 'Syntax: .anticheat jail [$name]\n\nSends GM and player $name (or selected player if not provided) to Jail for interrogation, also freezes player in place'),
('anticheat warn', 850, 'Syntax: .anticheat warn [$name]\n\nSends a ''friendly'' warning to player $name (or selected player if not provided)');
