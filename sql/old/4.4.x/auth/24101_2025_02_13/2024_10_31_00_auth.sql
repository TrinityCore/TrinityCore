DELETE FROM `build_info` WHERE `build` IN (57294);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57294,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57294 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57294 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57294 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57294 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57294,'Mac','A64','WoW',0x8122F4637E54772F141A221CF838023F),
(57294,'Mac','x64','WoW',0x20593AF7916DE92889DFAD00E56EC3E2),
(57294,'Win','A64','WoW',0xE082A35A1F6AC2C86FB3D9AE2564E0A7),
(57294,'Win','x64','WoW',0xCEAD7331A86E61C4119261FD2DA1BB43);
