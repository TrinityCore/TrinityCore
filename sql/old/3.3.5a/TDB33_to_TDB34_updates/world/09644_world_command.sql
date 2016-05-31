DELETE FROM command WHERE name IN ('reload all_gossips', 'reload locales_gossip_menu_option', 'reload quest_poi');
INSERT INTO command (name, security, help) VALUES
('reload all_gossips',3,'Syntax: .reload all_gossips\nReload gossip_menu, gossip_menu_option, gossip_scripts, npc_gossip, points_of_interest tables.'),
('reload locales_gossip_menu_option',3, 'Syntax: .reload locales_gossip_menu_option\nReload locales_gossip_menu_option table.'),
('reload quest_poi',3,'Syntax: .reload quest_poi\nReload quest_poi table.');