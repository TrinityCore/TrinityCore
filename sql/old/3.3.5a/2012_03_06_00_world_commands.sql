DELETE FROM `command` WHERE `name` = 'reload locales_creature_text';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('reload locales_creature_text', 3, 'Syntax: .reload locales_creature_text\nReload locales_creature_text Table.');