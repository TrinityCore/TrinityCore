-- Hotfixes database update data
TRUNCATE TABLE `updates_include`;
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/updates/hotfixes', 'RELEASED'),
('$/sql/custom/hotfixes', 'RELEASED'),
('$/sql/old/6.x/hotfixes', 'ARCHIVED');
