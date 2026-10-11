DELETE FROM `build_info` WHERE `build` IN (61265);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61265,11,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61265 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61265,'Mac','A64','WoW',0xDEA96215DAEE2552A432AE1F30753C3D),
(61265,'Mac','A64','WoWC',0x3AEED019A7B37FC429F0D484B8599D03),
(61265,'Mac','x64','WoW',0xDF74D9839DDE90D1681C83829BEE4904),
(61265,'Mac','x64','WoWC',0xA601E42069510E0D5EB08FE1155E21DF),
(61265,'Win','A64','WoW',0x87D07F5340DEC51CB965935E13A035A7),
(61265,'Win','x64','WoW',0xDAC655ECD4795C36E2A7DF63AB7E3915),
(61265,'Win','x64','WoWC',0xC06106A58586E5B0A13411BC53B8CFA5);

UPDATE `realmlist` SET `gamebuild`=61265 WHERE `gamebuild`=61188;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61265';
