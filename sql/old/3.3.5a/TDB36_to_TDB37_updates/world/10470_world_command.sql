DELETE FROM `command` WHERE `name` LIKE 'server togglequerylog';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('server togglequerylog',4,'Toggle SQL driver query logging.');
