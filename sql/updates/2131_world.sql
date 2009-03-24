DELETE FROM `command` WHERE `name` IN ('server difftime', 'npc addtemp', 'gobject addtemp', '');
INSERT INTO `command` VALUES
('gobject tempadd','2','Adds a temporary gameobject that is not saved to DB.'),
('npc tempadd','2','Adds temporary NPC, not saved to database.');
UPDATE `command` SET `name`="ahbotoption" WHERE `name`="ahbotoptions";
DELETE FROM `command` WHERE `name` IN ('reload tickets');
DELETE FROM `command` WHERE `name` LIKE "path%";
DELETE FROM `command` WHERE `name` LIKE "wp%";
INSERT INTO `command` VALUES 
('wp load',2,'Syntax: .path load $pathid\nLoad pathid number for selected creature. Creature must have no waypoint data.'),
('wp event',2,'Syntax: .path event $subcommand\nType .path event to see the list of possible subcommands or .help path event $subcommand to see info on subcommands.'),
('wp event add',2,'Syntax: .path event add $subcommand\nAdd new waypoint action in DB.'),
('wp event mod',2,'Syntax: .path mod $eventid $parameter $parameter_value\nModify parameter value for specified eventid.\nPossible parameters: pos_x, pos_y, pos_z, command, datalong, datalon2, dataint.'),
('wp event listid',2,'Syntax: .path event listid $eventid\nShows specified eventid info.'),
('wp unload',2,'Syntax: .path unload\nUnload path for selected creature.'),
('wp show',2,'Syntax: .path show $option\nOptions:\non $pathid (or selected creature with loaded path) - Show path\noff - Hide path\ninfo $slected_waypoint - Show info for selected waypoint.'),
('wp mod ',2,'Syntax: .path mod\nType .path mod to see the list of possible subcommands or .help path mod $subcommand to see info on subcommands.'),
('wp mod del',2,'Syntax: .path mod del\nDelete selected waypoint.'),
('wp mod move',2,'Syntax: .path mod move\nChange selected waypoint coordinates to your position.'),
('wp mod move_flag',2,'Syntax: .path mod move_flag\nSet move/run flag.'),
('wp mod action',2,'Syntax: .path mod action\nAssign action (waypoint script id) to selected waypoint.'),
('wp mod action_chance',2,'Syntax: .path mod action_chance\nAssign chance.');