INSERT INTO `world_config`(`OptionName`, `Type`, `IDInTypeGroup`, `DefaultValue`, `CustomValue`, `Description`) VALUES 
('Respawn.WarningMessage', 'string', 0, 'There will be an unscheduled server restart at 03:00. The server will be available again shortly after.', NULL, 'This message will be periodically shown (Frequency specified by Respawn.WarningFrequency) to all users of the server, once the Respawn.GuidWarnLevel has been passed, and a restart scheduled. It\'s used to warn users that there will be an out of schedule server restart soon.'),
('Respawn.AlertRestartReason', 'string', 1, 'Urgent Maintenance', NULL, 'The shutdown reason given when the alert level is reached. The server will use a fixed time of 5 minutes and the reason for shutdown will be this message'),
('Motd', 'string', 2, 'Welcome to a Trinity Core Server.', NULL, NULL),
('PlayerStart.String', 'string', 3, '', NULL, 'String to be displayed at first login of newly created characters.');
