DELETE FROM `command` WHERE `name` LIKE 'lookup spell id';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('lookup spell id', '3', 'Syntax: .lookup spell id #spellid\n\nLooks up a spell by #spellid, and returns the match with its spell name.');
