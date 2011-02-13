DELETE FROM `command` WHERE `name` IN ('server difftime', 'addmove', 'Mod32Value', 'allowmove', 'reload tickets', 'npc tempadd', 'gobject tempadd', 'gobject addtemp', 'npc addtemp');
INSERT INTO `command` VALUES
('gobject tempadd','2','Adds a temporary gameobject that is not saved to DB.'),
('npc tempadd','2','Adds temporary NPC, not saved to database.');
UPDATE `command` SET `name`="ahbotoption" WHERE `name`="ahbotoptions";
DELETE FROM `command` WHERE `name` LIKE "path%";
DELETE FROM `command` WHERE `name` LIKE "wp%";
INSERT INTO `command` VALUES 
('wp load',2,'Syntax: .wp load $pathid\nLoad pathid number for selected creature. Creature must have no waypoint data.'),
('wp event',2,'Syntax: .wp event $subcommand\nType .path event to see the list of possible subcommands or .help path event $subcommand to see info on subcommands.'),
('wp unload',2,'Syntax: .wp unload\nUnload path for selected creature.'),
('wp show',2,'Syntax: .wp show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\noff - Hide path\ninfo $slected_waypoint - Show info for selected waypoint.'),
('wp mod',2,'Syntax: .wp mod\nType .path mod to see the list of possible subcommands or .help path mod $subcommand to see info on subcommands.');
