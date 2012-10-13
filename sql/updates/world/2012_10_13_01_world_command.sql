DELETE FROM `command` WHERE `name`="npc info guid";
INSERT INTO `command` (`name`, `security`, `help`) VALUES
("npc info guid",3, "Syntax:.npc info guid\n\nDisplays a list of details for a creature, provided its database GUID.");
