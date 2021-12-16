DELETE FROM `command` WHERE `name` IN ('tele name npc id','tele name npc guid','tele name npc name');
INSERT INTO `command` (`name`,`help`) VALUES
('tele name npc id','Syntax: .tele name id #playername #creatureId

Teleport the given character to first found creature with id #creatureId. Character can be offline.'),
('tele name npc guid','Syntax: .tele name id #playername #creatureSpawnId

Teleport the given character to creature with spawn id #creatureSpawnId. Character can be offline.'),
('tele name npc name','Syntax: .tele name id #playername #creatureName

Teleport the given character to first found creature with name (must match exactly) #creatureName. Character can be offline.');
