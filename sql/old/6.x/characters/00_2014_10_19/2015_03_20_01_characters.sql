-- Characters database update data
TRUNCATE TABLE `updates_include`;
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/updates/characters', 'RELEASED'),
('$/sql/custom/characters', 'RELEASED'),
('$/sql/old/6.x/characters', 'ARCHIVED');
