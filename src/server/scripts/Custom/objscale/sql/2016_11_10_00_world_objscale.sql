-- gameobject
INSERT INTO `command` (`name`, `help`) VALUES ('gobject set scale', 'Syntax: .gobject set scale #guid #scale\r\n\r\nGameobject with DB guid #guid size changed to #scale. Gameobject scale saved to DB and persistent. Does not affect other gameobjects of same entry. Using -1 scale uses the default scale from template.');

-- creature
INSERT INTO `command` (`name`, `help`) VALUES ('npc set scale', 'Syntax: .npc set scale #scale\r\n\r\nSelected NPC size changed to #scale. NPC scale saved to DB and persistent. Does not affect other creatures of same entry. Using -1 scale uses the default scale from template.');
