DELETE FROM `battlenet_components` WHERE `Platform` IN ('ptBR', 'ptPT', 'itIT', 'enCN', 'enTW') AND `Program` = 'WoW';
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('WoW', 'ptBR', 0),
('WoW', 'ptPT', 0),
('WoW', 'itIT', 0),
('WoW', 'enCN', 0),
('WoW', 'enTW', 0);
