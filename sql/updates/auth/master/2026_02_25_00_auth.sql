DELETE FROM `build_info` WHERE `build` IN (66066);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66066,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66066 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66066,'Mac','A64','WoW',0x9CBF3EFCEFFEFADE1C6068590E9C633D),
(66066,'Mac','A64','WoWC',0x37F5A699D394AFB5654D0EF2D42DF893),
(66066,'Mac','x64','WoW',0x43C90F4352F8962F06D13699A60850E3),
(66066,'Mac','x64','WoWC',0xB1C25754B032A581D4C2E73EDA58FA1C),
(66066,'Win','A64','WoW',0x53CC37A17E9E38BEF2701BE7D3CD25E4),
(66066,'Win','x64','WoW',0x5A44AEEAF2FF5F680F9EC2DACF721E11),
(66066,'Win','x64','WoWC',0xCB403B66DB34DC703A318240FD733AA0);

UPDATE `realmlist` SET `gamebuild`=66066 WHERE `gamebuild`=66044;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66066';
