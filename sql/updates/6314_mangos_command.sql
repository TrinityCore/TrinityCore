DELETE FROM `command` WHERE `name` IN ('combatstop');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('combatstop',2,'Syntax: .combatstop [$playername]\r\nStop combat for selected character. If selected non-player then command applied to self. If $playername provided then attempt applied to online player $playername.');
