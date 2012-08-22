DELETE FROM `trinity_string` WHERE `entry` = 555;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(555,"SetData performed on [GUID: %u, entry: %u, name: %s] Field: %u, Data: %u, with %s");

DELETE FROM `command` WHERE `name` = "npc set data";
INSERT INTO `command` (`name`,`security`,`help`) VALUES
("npc set data", 3, "Syntax: .npc set data $field $data
Sets data for the selected creature. Used for testing Scripting");
