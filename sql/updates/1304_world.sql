delete from command where name in ('reload spell_linked_spell');
insert into command (name, security, help) values
('reload spell_linked_spell','3','Usage: .reload spell_linked_spell\r\nReloads the spell_linked_spell DB table.'), 
