DELETE FROM `build_info` WHERE `build` IN (66102);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66102,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66102 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66102,'Mac','A64','WoW',0x1F98D6A2D51D171627FF8A57F784CF99),
(66102,'Mac','A64','WoWC',0x61F4CC148B68485E601E853E4787F80B),
(66102,'Mac','x64','WoW',0x8F98EB2A0E4F48DC3A707430DF38A2ED),
(66102,'Mac','x64','WoWC',0x53450B13738F09E4056D29FA52BB97D1),
(66102,'Win','A64','WoW',0xBB8094EDF49428355CFA2B047534122A),
(66102,'Win','x64','WoW',0x9C5E4611B87738D89FE8A27C3AC3F375),
(66102,'Win','x64','WoWC',0xBDE323DD7628C72BDD953A0253CFF53E);

UPDATE `realmlist` SET `gamebuild`=66102 WHERE `gamebuild`=66066;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66102';
