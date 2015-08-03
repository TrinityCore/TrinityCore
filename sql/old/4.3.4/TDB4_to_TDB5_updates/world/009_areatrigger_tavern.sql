UPDATE `areatrigger_tavern` SET `name`='Feathermoon Stronghold' WHERE `id`=1024;
UPDATE `areatrigger_tavern` SET `name`='Farwatcher''s Glen - 01' WHERE `id`=6164;

DELETE FROM `areatrigger_tavern` WHERE `id` IN (6087, 6088, 6089, 6090, 6091, 6092, 6093, 6111, 6131, 6133, 6156, 6165, 6166, 6173, 6203, 6204, 6313, 6463, 6471, 6473, 6475, 6484, 6657);
INSERT INTO `areatrigger_tavern` (`id`, `name`) VALUES
(6087, 'Zoram''gar Outpost'),
(6088, 'Hellscream''s Watch - 01'),
(6089, 'Hellscream''s Watch - 02'),
(6090, 'Hellscream''s Watch - 03'),
(6091, 'Silverwind Refuge - 01'),
(6092, 'Silverwind Refuge - 02'),
(6093, 'Silverwind Refuge - 03'),
(6111, 'Bilgewater Harbor'),
(6131, 'Nozzlepot''s Outpost'),
(6133, 'Grol''dom Farm'),
(6156, 'Krom''gar Fortress'),
(6165, 'Farwatcher''s Glen - 02'),
(6166, 'Fort Livingston'),
(6173, 'Hardwrench Hideaway'),
(6203, 'Dreamer''s Rest'),
(6204, 'Camp Ataya'),
(6313, 'The Bulwark'),
(6463, 'Wildheart Point'),
(6471, 'Schnottz''s Landing - 01'),
(6473, 'Iron Summit'),
(6475, 'Schnottz''s Landing - 02'),
(6484, 'Dragon''s Mouth'),
(6657, 'Duskhaven');
