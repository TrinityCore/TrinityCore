UPDATE `areatrigger_tavern` SET `name`='Farstrider Lodge - 01' WHERE `id`=6122;

DELETE FROM `areatrigger_tavern` WHERE `id` IN (6440, 6443, 6185, 6186, 6187, 6188, 6189, 6190, 6191, 6192, 6193, 6121, 6123, 6124, 6125);
INSERT INTO `areatrigger_tavern` (`id`, `name`) VALUES
(6440, 'Bogpaddle'),
(6443, 'The Harborage'),
(6185, 'Honor''s Stand'),
(6186, 'Hunter''s Hill'),
(6187, 'Fort Triumph - 01'),
(6188, 'Fort Triumph - 02'),
(6189, 'Desolation Hold'),
(6190, 'Northwatch Hold'),
(6191, 'Dreadmaul Hold'),
(6192, 'Nethergarde Keep'),
(6193, 'Surwich'),
(6121, 'Karnum''s Glade'),
(6123, 'Farstrider Lodge - 02'),
(6124, 'Farstrider Lodge - 03'),
(6125, 'Marshal''s Stand');
