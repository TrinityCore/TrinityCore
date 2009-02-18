DELETE FROM `command` WHERE name IN ('bindsight', 'unbindsight');
INSERT INTO `command` (name,security,help) VALUES
('bindsight',3,'Syntax: .bindsight\r\n\r\nBinds vision to the selected unit indefinitely. Cannot be used while currently possessing a target.'),
('unbindsight',3,'Syntax: .unbindsight\r\n\r\nRemoves bound vision. Cannot be used while currently possessing a target.');

