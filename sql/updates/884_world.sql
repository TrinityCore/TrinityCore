delete from command where name in ('gobject tempadd','npc tempadd');
insert into command (name, security, help) values
('gobject addtemp','2','Adds a temporary gameobject that is not saved to DB.'),
('npc addtemp','2','Adds temporary NPC, not saved to database.');

