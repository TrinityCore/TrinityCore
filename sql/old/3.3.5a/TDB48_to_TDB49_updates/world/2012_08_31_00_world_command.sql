DELETE FROM `command` WHERE `name`='explorecheat';
DELETE FROM `command` WHERE `name`='taxicheat';
DELETE FROM `command` WHERE `name`='waterwalk';

DELETE FROM `command` WHERE `name`='cheat' OR `name` LIKE 'cheat%';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('cheat',           2, 'Syntax: .cheat $subcommand\r\nType .cheat to see the list of possible subcommands or .help cheat $subcommand to see info on subcommands'),
('cheat god',       2, 'Syntax: .cheat god [on/off]\r\nEnables or disables your character''s ability to take damage.'),
('cheat casttime',  2, 'Syntax: .cheat casttime [on/off]\r\nEnables or disables your character''s spell cast times.'),
('cheat cooldown',  2, 'Syntax: .cheat cooldown [on/off]\r\nEnables or disables your character''s spell cooldowns.'),
('cheat power',     2, 'Syntax: .cheat power [on/off]\r\nEnables or disables your character''s spell cost (e.g mana).'),
('cheat waterwalk', 2, 'Syntax: .cheat waterwalk on/off\r\nSet on/off waterwalk state for selected player or self if no player selected.'),
('cheat explore',   2, 'Syntax: .cheat explore #flag\r\nReveal or hide all maps for the selected player. If no player is selected, hide or reveal maps to you.\r\nUse a #flag of value 1 to reveal, use a #flag value of 0 to hide all maps.'),
('cheat taxi',      2, 'Syntax: .cheat taxi on/off\r\nTemporary grant access or remove to all taxi routes for the selected character.\r\n If no character is selected, hide or reveal all routes to you.Visited taxi nodes sill accessible after removing access.');
