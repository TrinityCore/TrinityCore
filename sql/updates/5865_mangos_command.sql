DELETE FROM `command` WHERE `name` = 'cast self';

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('cast self',3,'Syntax: .cast self #spellid\r\nCast #spellid by target at target itself.');
