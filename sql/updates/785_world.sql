delete from command where name in ('gobject addtemp', 'npc addtemp');
insert into command (name, security, help) values
('gobject addtemp','2','Adds a temporary gameobject that is not saved to DB.'),
('npc addtemp','2','Adds temporary NPC, not saved to database.');
