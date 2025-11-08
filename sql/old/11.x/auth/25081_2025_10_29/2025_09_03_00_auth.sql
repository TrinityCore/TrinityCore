DELETE FROM `build_info` WHERE `build` IN (62958);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62958,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62958 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62958,'Mac','A64','WoW',0xEE77D6BFA45BABF53FE4C772574599A6),
(62958,'Mac','A64','WoWC',0x7D3860F9B0E9E539920142F4EAEC860D),
(62958,'Mac','x64','WoW',0x63FBEC08A7D15969549287392C7CB19A),
(62958,'Mac','x64','WoWC',0x32316C8B3AF4FDCF7A67FD7769A7F12B),
(62958,'Win','A64','WoW',0x9E640307050295A43A034A1DDA8A4814),
(62958,'Win','x64','WoW',0xD72F913B55C92C58450FCFB68704783F),
(62958,'Win','x64','WoWC',0x6E767AD759A2B19C289127A4D4AEAD1F);

UPDATE `realmlist` SET `gamebuild`=62958 WHERE `gamebuild`=62876;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62958';
