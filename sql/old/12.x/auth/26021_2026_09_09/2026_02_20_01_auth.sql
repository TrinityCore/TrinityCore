DELETE FROM `build_info` WHERE `build` IN (66044);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66044,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66044 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66044,'Mac','A64','WoW',0x5BF016B4A84F9F4CD865C12EC0A06FA5),
(66044,'Mac','A64','WoWC',0xB19684F437581DDF1EDA5832DE5F714C),
(66044,'Mac','x64','WoW',0x7E8E5B5D073F28869E6D60B45574E34B),
(66044,'Mac','x64','WoWC',0x1BAB06776EAFBF6891B246935A49F749),
(66044,'Win','A64','WoW',0xB9746F34D79C991A793193F12F0F3F42),
(66044,'Win','x64','WoW',0x32BA84E996F83AEF4E9B6771FEF20243),
(66044,'Win','x64','WoWC',0xAC494B5B4915AF8B2C870BE360A81DC2);

UPDATE `realmlist` SET `gamebuild`=66044 WHERE `gamebuild`=66017;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66044';
