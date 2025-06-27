-- Auth database update data
TRUNCATE TABLE `updates_include`;
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/updates/auth', 'RELEASED'),
('$/sql/custom/auth', 'RELEASED'),
('$/sql/old/3.3.5a/auth', 'ARCHIVED');
