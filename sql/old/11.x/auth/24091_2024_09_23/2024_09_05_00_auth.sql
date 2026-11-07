DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56421,'Mac','A64','WoWC',0x629666D6D9EFFE4B73C1EDD74638DEAA),
(56421,'Mac','x64','WoWC',0x4B61E4F4F3B220FF5B48A6988F0FFB42),
(56421,'Mac','x64','WoW',0x4F0FCD1113F783C484BF45C98327DE62),
(56421,'Win','A64','WoW',0x178888C71560707CC9C1C1D6B45B4838);
