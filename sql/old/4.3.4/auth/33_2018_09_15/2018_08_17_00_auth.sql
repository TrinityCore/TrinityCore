DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'frFR';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'esES';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'esMX';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'ptBR';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'ptPT';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'ruRU';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'zhCN';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'zhTW';
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('WoW', 'frFR', 15595),
('WoW', 'esES', 15595),
('WoW', 'esMX', 15595),
('WoW', 'ptPT', 15595),
('WoW', 'ptBR', 15595),
('WoW', 'ruRU', 15595),
('WoW', 'zhCN', 15595),
('WoW', 'zhTW', 15595);

