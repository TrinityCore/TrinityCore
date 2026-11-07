DELETE FROM `build_info` WHERE `build` IN (56819);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56819,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56819 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56819,'Mac','A64','WoW',0x1553CD215A62E2DC92CD61C4FB5DF9C3),
(56819,'Mac','A64','WoWC',0x1B7EF05D342064F931E53264031E3497),
(56819,'Mac','x64','WoW',0x9D5B7E1B5E59E54A3B96E5CCBA6EF465),
(56819,'Mac','x64','WoWC',0x2BDCD952BAA47E6CBD71C780BC8CCD47),
(56819,'Win','A64','WoW',0x7DC752479B560884B8289BC5B5C85F3F),
(56819,'Win','x64','WoW',0x4373F45E9D617636332569671ED5D5E9),
(56819,'Win','x64','WoWC',0xB9E422DF76DA635E193B75BD54ADD8DE);

UPDATE `realmlist` SET `gamebuild`=56819 WHERE `gamebuild`=56647;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56819';
