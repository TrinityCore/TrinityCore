UPDATE `areatrigger_tavern` SET `name`='Hammerfall' WHERE `id`=1646;
UPDATE `areatrigger_tavern` SET `name`='Taren Mill' WHERE `id`=721;

DELETE FROM `areatrigger_tavern` WHERE `id` IN (6106, 6110, 6155, 6314, 6467, 6577, 6589, 6590, 6592, 6600, 6602, 6603, 6604, 6605, 6606, 6607, 6608, 6609, 6615, 6616);
INSERT INTO `areatrigger_tavern` (`id`, `name`) VALUES
(6106, 'Stormfeather Outpost'),
(6110, 'Hiri''watha Research Station'),
(6155, 'Refuge Pointe'),
(6314, 'Chillwind Camp'),
(6467, 'Andorhal'),
(6577, 'The Sludge Fields'),
(6589, 'Crushblow'),
(6590, 'Victor''s Point'),
(6592, 'The Krazzworks'),
(6600, 'Thundermar - 01'),
(6602, 'Thundermar - 02'),
(6603, 'Bloodgulch - 01'),
(6604, 'Bloodgulch - 02'),
(6605, 'Firebeard''s Patrol - 01'),
(6606, 'Firebeard''s Patrol - 02'),
(6607, 'Firebeard''s Patrol - 03'),
(6608, 'Dragonmaw Port - 01'),
(6609, 'Dragonmaw Port - 02'),
(6615, 'Highbank - 01'),
(6616, 'Highbank - 02');
