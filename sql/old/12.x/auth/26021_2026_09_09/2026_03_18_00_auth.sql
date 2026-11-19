DELETE FROM `build_info` WHERE `build` IN (66431);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66431,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66431 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66431,'Mac','A64','WoW',0x88DAAF8AB8C7D7966C9953DA6B8891D1),
(66431,'Mac','A64','WoWC',0x1C8CF7074A759E2E21438177FC9F56C5),
(66431,'Mac','x64','WoW',0x7AC8F50FBDBF998B4ED2728CFE62DE5D),
(66431,'Mac','x64','WoWC',0xA6DEF2B52C483C91534BFA1FF622A694),
(66431,'Win','A64','WoW',0x76EC3154E6F38F0DB788B47153F12F19),
(66431,'Win','x64','WoW',0x5CEE32E409DEB66CF3FBC62830FCFC5C),
(66431,'Win','x64','WoWC',0xC72DF90134ACA394596DFB106682267C);

UPDATE `realmlist` SET `gamebuild`=66431 WHERE `gamebuild`=66384;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66431';
