-- Emerald Dream instance_template
DELETE FROM instance_template WHERE map = 169 AND script = 'emerald_dream';
INSERT INTO instance_template (map, parent, script, allowMount) VALUES ('169', '0', 'emerald_dream', '0');