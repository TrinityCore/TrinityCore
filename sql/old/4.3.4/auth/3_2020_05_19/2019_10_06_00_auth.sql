DELETE FROM `battlenet_components` WHERE `Platform` IN ('Mac', 'Mc64');
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('Bnet', 'Mac', 26487),
('Bnet', 'Mc64', 26487),
('WoW', 'Mac', 15595),
('WoW', 'Mc64', 15595),
('Tool', 'Mac', 0),
('Tool', 'Mc64', 0);

DELETE FROM `battlenet_components` WHERE `Platform`= 'Wn64' AND `Program`= 'Tool';
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('Tool', 'Wn64', 0);

DELETE FROM `battlenet_components` WHERE `Platform` IN ('enTW', 'enCN', 'koKR');
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('WoW', 'enTW', 15595),
('WoW', 'enCN', 15595),
('WoW', 'koKR', 15595);
