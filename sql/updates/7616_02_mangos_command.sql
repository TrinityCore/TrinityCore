ALTER TABLE db_version CHANGE COLUMN required_7616_01_mangos_mangos_string required_7616_02_mangos_command bit;

DELETE FROM `command` WHERE `name` IN ('debug playsound','debug play sound','debug play cinematic','debug play movie');

INSERT INTO `command` VALUES
('debug play cinematic',1,'Syntax: .debug play cinematic #cinematicid\r\n\r\nPlay cinematic #cinematicid for you. You stay at place while your mind fly.\r\n'),
('debug play movie',1,'Syntax: .debug play movie #movieid\r\n\r\nPlay movie #movieid for you.'),
('debug play sound',1,'Syntax: .debug play sound #soundid\r\n\r\nPlay sound with #soundid.\r\nSound will be play only for you. Other players do not hear this.\r\nWarning: client may have more 5000 sounds...');
