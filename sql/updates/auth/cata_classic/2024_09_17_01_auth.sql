DELETE FROM `build_auth_key` WHERE `build`=56489 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56489 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56489 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56489 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56489,'Mac','A64','WoW',0x6A8C974BCAF78D6E2032E3B5776D89FA),
(56489,'Mac','x64','WoW',0x482A7A1DCE05F878626F1B1D52BFA80B),
(56489,'Win','A64','WoW',0xC0FA9CBF98C21ED7F062AB8ED5A34B50),
(56489,'Win','x64','WoW',0xA3FC116BB68FA279DBB66B4024305D99);
