DELETE FROM `trinity_string` WHERE `entry` IN (5073, 5074);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES 
(5073, 'Selected creature reloaded.'),
(5074, 'Selected creature and all same entries in vision range reloaded.');

DELETE FROM `command` WHERE `name`='npc reload';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES
('npc reload', 2006, 'Syntax: .npc reload [all]\n\nReloads selected creature or all same creatures in vision range if #all argument is provided\nRespawns creature, reloads it\'s template, addon, aura, ai/script, etc data\nNote: it does not reload smart_scripts table');
