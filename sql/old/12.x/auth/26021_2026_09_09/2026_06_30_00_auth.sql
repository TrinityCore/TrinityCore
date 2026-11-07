DELETE FROM `build_info` WHERE `build` IN (68367);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(68367,12,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68367 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(68367,'Mac','A64','WoW',0xDD147AA0ABD7278CAB4899E9445F0208),
(68367,'Mac','A64','WoWC',0x2DD84BB165DB406107586AC1871007DA),
(68367,'Mac','x64','WoW',0x2A26C5E2BB711811C4B9715279CCE5F2),
(68367,'Mac','x64','WoWC',0x4F03B7F7B58588F83EE916B355F537D6),
(68367,'Win','A64','WoW',0x01EED68AAB9B396F6E34FBF7D1DA653E),
(68367,'Win','x64','WoW',0x960CB7E237088E4B37C145F81A8B8F2D),
(68367,'Win','x64','WoWC',0xA35FB9F41A11A3458949BEE1C7E7E41D);

UPDATE `realmlist` SET `gamebuild`=68367 WHERE `gamebuild`=68275;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68367';
