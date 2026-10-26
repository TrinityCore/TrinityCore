DELETE FROM `build_info` WHERE `build` IN (67602);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67602,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67602 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67602,'Mac','A64','WoW',0x89E2CEB6AE2890997DB03BB332BEC59E),
(67602,'Mac','A64','WoWC',0xC1BD2C01B0EAC4580B427A6DEEDC48A0),
(67602,'Mac','x64','WoW',0x4A9D243A9A4919936FE5CAC7024F920F),
(67602,'Mac','x64','WoWC',0x31289BB2115BA7A778D4E54FFF638296),
(67602,'Win','A64','WoW',0x2E7F2CE7A255EF8697D07B586B113820),
(67602,'Win','x64','WoW',0x7364F24CDF8CECE86ED8D6C9D26DE012),
(67602,'Win','x64','WoWC',0xB1140CD65B6D22D08BB7C91689493C71);

UPDATE `realmlist` SET `gamebuild`=67602 WHERE `gamebuild`=67451;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67602';
