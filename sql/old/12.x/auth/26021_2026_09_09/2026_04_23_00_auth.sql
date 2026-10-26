DELETE FROM `build_info` WHERE `build` IN (67114);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67114,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67114 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67114,'Mac','A64','WoW',0x1A1662F9D15F926D6A85DF91BCE79DF1),
(67114,'Mac','A64','WoWC',0xD28D8D2C35FA6FE4C3C0D76894431F46),
(67114,'Mac','x64','WoW',0x59407231B082F7587562AC40C6992613),
(67114,'Mac','x64','WoWC',0x02E25F13D33F7486F2267D23D527D0FE),
(67114,'Win','A64','WoW',0x275017EC612F2E13305A0FA0C16A5FA8),
(67114,'Win','x64','WoW',0x43F598C4E67C9D2F644A560369C0DF41),
(67114,'Win','x64','WoWC',0x1F88AE965BD17EE37189BD736C5F7D7B);

UPDATE `realmlist` SET `gamebuild`=67114 WHERE `gamebuild`=67088;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67114';
