DELETE FROM `build_info` WHERE `build` IN (66337);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66337,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66337 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66337,'Mac','A64','WoW',0xEEF9108052A64B5DD11F63297443E43C),
(66337,'Mac','A64','WoWC',0xA6FBFAB9899D6AE4C3ADAE17F798D265),
(66337,'Mac','x64','WoW',0x8B13D4DCD13E77395E9B38FCEAA3FCEC),
(66337,'Mac','x64','WoWC',0x0E3526BF6DCFD4393D9C41D6841F8B19),
(66337,'Win','A64','WoW',0x40F91099F5A68C7736DB3A36CDCD8F3E),
(66337,'Win','x64','WoW',0x679204D38B88E9455769E3159E937068),
(66337,'Win','x64','WoWC',0xFF6DA0F5B97AEBE3EB56AC2EC1C2A5DB);

UPDATE `realmlist` SET `gamebuild`=66337 WHERE `gamebuild`=66263;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66337';
