DELETE FROM command WHERE name = 'reload conditions';
INSERT INTO command (name, security, help) VALUES ('reload conditions', 3, 'Reload conditions table.');
