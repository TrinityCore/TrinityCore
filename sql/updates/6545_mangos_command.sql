DELETE FROM `command` WHERE name IN ('idleshutdown','info','shutdown','server info','server shutdown','server restart','server idleshutdown','server idlerestart');
INSERT INTO `command` VALUES
('server info',0,'Syntax: .server info\r\n\r\nDisplay server version and the number of connected players.'),
('server shutdown',3,'Syntax: .server shutdown seconds\r\n\r\nShut the server down after given seconds and show "Off server in X" or cancel the restart/shutdown if cancel value is used.'),
('server restart',3,'Syntax: .server restart seconds\r\n\r\nRestart the server after given seconds and show "Restart server in X" or cancel the restart/shutdown if cancel value is used.'),
('server idleshutdown',3,'Syntax: .server idleshutdown #delay|cancel\r\n\r\nShut the server down after #delay seconds if no active connections are present (no players) or cancel the restart/shutdown if cancel value is used.'),
('server idlerestart',3,'Syntax: .server idlerestart #delay|cancel\r\n\r\nRestart the server after #delay seconds if no active connections are present (no players) or cancel the restart/shutdown if cancel value is used.');
