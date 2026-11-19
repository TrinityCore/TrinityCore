DELETE FROM `build_info` WHERE `build` IN (56513);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56513,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56513 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56513,'Mac','A64','WoW',0xC7E757E0DE67619251F942B6C98A53B7),
(56513,'Mac','A64','WoWC',0x3CC0640E46D557C4D9A6250AA8D5B387),
(56513,'Mac','x64','WoW',0xD1443824E37B73CB1FD993CE2DFAA098),
(56513,'Mac','x64','WoWC',0xEAD9A0B761C4C9C812FAD54CE0D96B46),
(56513,'Win','A64','WoW',0x753468F753E8D3841B5D6B061E300501),
(56513,'Win','x64','WoW',0x9BD8D105049CC6459FE32EC7099AB60E),
(56513,'Win','x64','WoWC',0xBB5A35C2EB6E2026FFE01202FDEBD6E9);

UPDATE `realmlist` SET `gamebuild`=56513 WHERE `gamebuild`=56461;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56513';
