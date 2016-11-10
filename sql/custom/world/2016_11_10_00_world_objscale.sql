-- gameobject
ALTER TABLE `gameobject`ADD COLUMN `size` FLOAT NOT NULL DEFAULT '-1';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('gobject set scale', 1398, 'Syntax: .gobject set scale #guid #scale\r\n\r\nGameobject with DB guid #guid size changed to #scale. Gameobject scale saved to DB and persistent. Does not affect other gameobjects of same entry. Using -1 scale uses the default scale from template.');

-- creature
ALTER TABLE `creature` ADD COLUMN `size` FLOAT NOT NULL DEFAULT '-1';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES ('npc set scale', 1589, 'Syntax: .npc set scale #scale\r\n\r\nSelected NPC size changed to #scale. NPC scale saved to DB and persistent. Does not affect other creatures of same entry. Using -1 scale uses the default scale from template.');
