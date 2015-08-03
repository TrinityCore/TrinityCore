DELETE FROM `command` WHERE name='quest reward';
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('quest reward',3,'Syntax: .quest reward #questId\n\n\Grants quest reward to selected player and removes quest from his log (quest must be in completed state).');
