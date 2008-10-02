DELETE FROM `command` WHERE `name` IN ('combatstop');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('combatstop',2,'Syntax: .combatstop\r\nStop combat for selected character. If selected non-player then command applied to self.');
