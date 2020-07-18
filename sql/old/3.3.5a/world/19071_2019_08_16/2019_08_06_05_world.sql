-- 
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1205 AND 1211;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1205, 'No bosses were found matching your input.'),
(1206, 'Multiple bosses match your input - please be more specific:'),
(1207, '|- #%05u \'%s\' (%s)'),
(1208, 'Multiple spawn points exist for boss \'%s\' (creature #%05u) - go to one using .go creature:'),
(1209, '|- %06u (map #%03u \'%s\' at %s)'),
(1210, 'Failed to teleport you to spawn point %u for boss \'%s\' (creature #%05u) - are you missing an attunement for map \'%s\'?'),
(1211, 'Teleported you to spawn point for boss \'%s\' (creature #%05u, spawnid %u)');

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1189 AND 1198;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1189, 'No instances were found matching your input.'),
(1190, 'Multiple instances match your input - please be more specific:'),
(1191,'|- \'%s\' (map #%03u, %s)'),
-- 1192 is newly unused
(1193,'Could not find entrance portal for map \'%s\' (map #%03u)'),
(1194,'Could not find exit portal for map \'%s\' (map #%03u)'),
(1195,'Teleported you to the entrance of \'%s\' (map #%03u)'),
(1196,'Teleported you to the start of \'%s\' (map #%03u)'),
(1197,'Failed to teleport you to the entrance of \'%s\' (map #%03u) - are you missing an attunement for map \'%s\' (#%03u)?'),
(1198,'Failed to teleport you to the start of \'%s\' (map #%03u) - are you missing an attunement for the instance?');

DELETE FROM `command` WHERE `name` IN ('go boss','go instance');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('go instance', 377, 'Syntax: .go instance <part(s) of name>
Teleport yourself to the instance whose name and/or script name best matches the specified search string(s).'),
('go boss', 377, 'Syntax: .go boss <part(s) of name>
Teleport yourself to the dungeon boss whose name and/or script name best matches the specified search string(s).');
