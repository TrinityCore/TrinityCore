DELETE FROM `command` WHERE `name` IN ('gobject tempadd','npc tempadd');
INSERT INTO `command` (name, security, help) VALUES
('gobject addtemp','2','Adds a temporary gameobject that is not saved to DB.'),
('npc addtemp','2','Adds temporary NPC, not saved to database.');