DELETE FROM `command` WHERE `name` = 'npc delete guid';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('npc delete guid', 3, 'Syntax: .npc delete guid $guid \n\n Removes a creature by guid.');
