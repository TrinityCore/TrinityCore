DELETE FROM `command` WHERE `name` IN ('gobject addtemp','npc addtemp');
INSERT INTO `command` (name, security, help) VALUES
('gobject addtemp','2','Adds a temporary gameobject that is not saved to DB.'),
('npc addtemp','2','Adds temporary NPC, not saved to database.');