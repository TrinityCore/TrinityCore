DELETE FROM `build_info` WHERE `build` IN (63003);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63003,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63003 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63003,'Mac','A64','WoW',0x11C3DFF1F900B7144DD1C60059D73E6F),
(63003,'Mac','A64','WoWC',0x3BACD112C004A649039B6E9B95833B9F),
(63003,'Mac','x64','WoW',0x7CE021E303D8D253F7231AAF4D06EC4A),
(63003,'Mac','x64','WoWC',0x51747BD29A6B1D635D88D8EA52F6D341),
(63003,'Win','A64','WoW',0x0400F2403DD8EDF9D3DEF5AF511FA6DC),
(63003,'Win','x64','WoW',0x6D1E354D17FB3885568FD704B87F98C2),
(63003,'Win','x64','WoWC',0x082C75D4F7115F904230A5716E17995A);

UPDATE `realmlist` SET `gamebuild`=63003 WHERE `gamebuild`=62958;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63003';
