DELETE FROM `build_info` WHERE `build` IN (61491);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61491,11,1,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61491 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61491,'Mac','A64','WoW',0x6A63F9B14228B85AF4EE9F6AAD2DC108),
(61491,'Mac','A64','WoWC',0x0F263AA0C47B7F9AF2DECC62CFBC87B8),
(61491,'Mac','x64','WoW',0x42754222FBEF4B872AB34F5A53166707),
(61491,'Mac','x64','WoWC',0x9513DE4CAB9E345FE327A216B9C4CAF3),
(61491,'Win','A64','WoW',0xA42E81E60866C0114F59CE5F5F6458D4),
(61491,'Win','x64','WoW',0xECE38E2B4833BA220C3C33EED4C004D1),
(61491,'Win','x64','WoWC',0x4E106C27490D03932C7985F192AC35E6);

UPDATE `realmlist` SET `gamebuild`=61491 WHERE `gamebuild`=61265;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61491';
