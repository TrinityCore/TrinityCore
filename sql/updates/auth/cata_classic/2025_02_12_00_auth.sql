DELETE FROM `build_info` WHERE `build` IN (59069);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59069,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59069 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59069,'Mac','A64','WoW',0xE6E34A403857D69026E1B4BAF75069CB),
(59069,'Mac','A64','WoWC',0x20447F7BAEFE1A765D5BCE343FE8EFFC),
(59069,'Mac','x64','WoW',0xF064E14A80A27B1BBCAE88C914D73E98),
(59069,'Mac','x64','WoWC',0x789EB4CF15BD2F2BF2E35768670B233E),
(59069,'Win','A64','WoW',0x44BF0502E2D95262727674CAA60E2E0F),
(59069,'Win','x64','WoW',0x8C9B002B8EF6BFD44169842E8185706A),
(59069,'Win','x64','WoWC',0x80DD4C1B6DF383AE5580402945D00052);

UPDATE `realmlist` SET `gamebuild`=59069 WHERE `gamebuild`=58558;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59069';
