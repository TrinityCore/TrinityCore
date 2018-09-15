UPDATE `battlenet_components` SET `Build`= 0 WHERE `Program`= 'Tool';
DELETE FROM `battlenet_components` WHERE `Program`= 'WoW' AND `Platform`= 'deDE';
INSERT INTO `battlenet_components` (`Program`, `Platform`, `Build`) VALUES
('WoW', 'deDE', 15595);
