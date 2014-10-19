DELETE FROM `command` WHERE `permission` IN (631,632,633,634,635,636,637,638,639,640);
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('reload creature_linked_respawn', 633, 'Syntax: .reload creature_linked_respawn\r\nReload creature_linked_respawn table.'),
('reload creature_loot_template', 634, 'Syntax: .reload creature_loot_template\nReload creature_loot_template table.'),
('reload creature_onkill_reputation', 635, 'Syntax: .reload creature_onkill_reputation\r\nReload creature_onkill_reputation table.'),
('reload creature_questender', 636, 'Syntax: .reload creature_questender\nReload creature_questender table.'),
('reload creature_queststarter', 637, 'Syntax: .reload creature_queststarter\nReload creature_queststarter table.'),
('reload creature_summon_groups', 638, 'Syntax: .reload creature_summon_groups\nReload creature_summon_groups table.'),
('reload creature_template', 639, 'Syntax: .reload creature_template $entry\r\nReload the specified creature''s template.'),
('reload creature_text', 640, 'Syntax: .reload creature_text\nReload creature_text Table.');
