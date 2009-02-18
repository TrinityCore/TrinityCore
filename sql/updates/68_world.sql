-- add lang strings
DELETE FROM trinity_string WHERE entry BETWEEN 1000 AND 1006;
INSERT INTO trinity_string VALUES
(1000,'You froze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1001,'It might be amusing but no... you cant freeze yourself!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1002,'Invalid input check the name of target.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1003,'You unfroze player %s.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1004,'There are no frozen players.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1005,'Following players are frozen on the server:',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1006,'- %s',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

-- add commands
DELETE FROM `command` WHERE `name` = 'freeze' or `name` = 'unfreeze' or name = 'listfreeze';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('freeze','2','Syntax: .freeze (#player)\r\n\"Freezes\" #player and disables his chat. When using this without #name it will freeze your target.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('unfreeze','2','Syntax: .unfreeze (#player)\r\n\"Unfreezes\" #player and enables his chat again. When using this without #name it will unfreeze your target.');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('listfreeze','1','Syntax: .listfreeze\r\n\r\nSearch and output all frozen players.');

