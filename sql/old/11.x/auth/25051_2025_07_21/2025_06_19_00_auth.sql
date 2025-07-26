DELETE FROM `build_info` WHERE `build` IN (61559);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61559,11,1,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61559 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61559,'Mac','A64','WoW',0x3C0726C9D66742F43C8D105C015364CF),
(61559,'Mac','A64','WoWC',0x32F6AB87E9E9776BEAACE8B6683A39BA),
(61559,'Mac','x64','WoW',0xD2039CB1EEE0B59595E145B8A9626001),
(61559,'Mac','x64','WoWC',0xE73978C9576833F36694293036E55409),
(61559,'Win','A64','WoW',0xAA7AD5624979EB36A6963A9F7DE019B9),
(61559,'Win','x64','WoW',0x17928A7329F53E273891D85A973248C0),
(61559,'Win','x64','WoWC',0xD9E57238DD0742B44E68F05D59A6234B);

UPDATE `realmlist` SET `gamebuild`=61559 WHERE `gamebuild`=61491;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61559';
