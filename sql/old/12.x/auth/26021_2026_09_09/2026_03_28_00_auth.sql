DELETE FROM `build_info` WHERE `build` IN (66709);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66709,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66709 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66709,'Mac','A64','WoW',0x396B922D343C50BEBEBFC74D30ED08C3),
(66709,'Mac','A64','WoWC',0x22D9162DE5B1812997AE2103DB7E0A7B),
(66709,'Mac','x64','WoW',0x86D1677AE56A5E8081FF6A2DA57B1D3F),
(66709,'Mac','x64','WoWC',0x09FA12BA5EFFAB4991B67C8023859A0F),
(66709,'Win','A64','WoW',0x57B21A0711347B6C331700CDB99D8062),
(66709,'Win','x64','WoW',0xA5BE6D5379CADEE2D78ECF1F8D2B655B),
(66709,'Win','x64','WoWC',0x3099082D2374A9BDBCEF42B00811383A);

UPDATE `realmlist` SET `gamebuild`=66709 WHERE `gamebuild`=66666;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66709';
