DELETE FROM `command` WHERE `name` IN ('reload creature_linked_respawn', 'npc setlink');
INSERT INTO `command` (`name`,`security`,`help`) VALUES 
('reload creature_linked_respawn',2,'Syntax: .reload creature_linked_respawn\r\nReload creature_linked_respawn table.'),
('npc setlink',2,'Syntax: .npc setlink $creatureGUID\r\n\r\nLinks respawn of selected creature to the condition that $creatureGUID defined is alive.');