-- 
DELETE FROM `command` WHERE `name` IN ('go creature', 'go creature id', 'go object', 'go gameobject', 'go gameobject id', 'go graveyard', 'go grid', 'go instance', 'go offset', 'go taxinode', 'go ticket', 'go trigger', 'go areatrigger', 'go xyz', 'go zonexy');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('go creature', 377, 'Syntax: .go creature <spawnId>
Teleport yourself to the creature spawn with the specified spawn ID.'),
('go creature id', 377, 'Syntax: .go creature id <creatureId>
Teleport yourself to the first spawn point for the specified creature ID.
If multiple spawn points for the creature exist, teleport to the first one found.'),
('go gameobject', 377, 'Syntax: .go gameobject <spawnId>
Teleport yourself to the gameobject spawn with the specified spawn ID.'),
('go gameobject id', 377, 'Syntax: .go gameobject id <goId>
Teleport yourself to the first spawn point for the specified gameobject ID.
If multiple spawn points for the gameobject exist, teleport to the first one found.'),
('go graveyard', 377, 'Syntax: .go graveyard <graveyardId>
Teleport yourself to the graveyard with the specified graveyard ID.'),
('go grid', 377, 'Syntax: .go grid <gridX> <gridY> [<mapId>]
Teleport yourself to center of grid at the provided indices in specified (or current) map.'),
('go instance', 377, 'Syntax: .go instance <part of scriptname>
Teleport yourself to the entrance of the instance matching the specified script name.'),
('go offset', 377, 'Syntax: .go offset [<dForward> [<dSideways> [<dZ [<dO>]]]]
Teleport yourself by the specified amount relative to your current position and orientation.'),
('go taxinode', 377, 'Syntax: .go taxinode <nodeId>
Teleport yourself to the specified taxi node.'),
('go ticket', 377, 'Syntax: .go ticket <ticketId>
Teleport yourself to the location at which the specified ticket was created.'),
('go areatrigger', 377, 'Syntax: .go areatrigger <areatriggerId>
Teleport yourself to the specified areatrigger\'s location.
Note that you may end up at the trigger\'s target location if it is a teleport trigger.'),
('go xyz', 377, 'Syntax: .go xyz <x> <y> [<z> [<mapid> [<o>]]]
Teleport yourself to the specified location in the specified (or current) map.
If no z coordinate is specified, defaults to ground/water level.'),
('go zonexy', 377, 'Syntax: .go zonexy <x> <y> [<zone>]
Teleport yourself to the given local (x,y) position in the specified (or current) zone.');
