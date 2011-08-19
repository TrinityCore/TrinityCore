DELETE FROM `command` WHERE name IN ('possess', 'unpossess');
INSERT INTO `command` (name,security,help) VALUES
('possess',3,'Syntax: .possess\r\n\r\nPossesses indefinitely the selected creature.'),
('unpossess',3,'Syntax: .unpossess\r\n\r\nIf you are possessed, unpossesses yourself; otherwise unpossesses current possessed target.');
