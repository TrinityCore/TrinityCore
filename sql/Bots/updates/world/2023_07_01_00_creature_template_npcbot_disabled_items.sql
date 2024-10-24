-- Test items: 'LK ARENA ...', 'LK Arena ...', 'LK Honor ...' (SELECT entry,name FROM item_template WHERE name LIKE 'LK %';)
INSERT IGNORE INTO `creature_template_npcbot_disabled_items` (`id`) VALUES
('42000'),
('42019'),
('41995'),
('42007'),
('42013'),
('40650'),
('41900'),
('41911'),
('42083');
