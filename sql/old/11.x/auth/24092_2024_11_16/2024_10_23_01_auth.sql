DELETE FROM `build_info` WHERE `build` IN (57212);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57212,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57212 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57212,'Mac','A64','WoW',0x5AF00EAFB241FAA2AF7485FA62AA094E),
(57212,'Mac','A64','WoWC',0xA4B115B6BA907AEC5AEF622F813BD81C),
(57212,'Mac','x64','WoW',0xFB59E41DAC6FF691A87A20696B3AC44E),
(57212,'Mac','x64','WoWC',0x32EB0F3BB5EA60EEC4945F71DBD2B4F3),
(57212,'Win','A64','WoW',0xA1D949D062EC49E5A2978BD1932C8D0E),
(57212,'Win','x64','WoW',0xB8ADB57D27EF98C8DDEF9943BE07EE94),
(57212,'Win','x64','WoWC',0xD18B79CEF34B5E10BA8C779EFE6D9EA0);
