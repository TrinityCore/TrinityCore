DELETE FROM `command` WHERE `name` = "cheat status" LIMIT 1;
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('cheat status', 2, 'Syntax: .cheat status \n\nShows the cheats you currently have enabled.');
