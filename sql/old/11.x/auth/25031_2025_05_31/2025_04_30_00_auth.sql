DELETE FROM `build_info` WHERE `build` IN (60568);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60568,11,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60568 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60568,'Mac','A64','WoW',0x470C274987087337796E8B9E2CAE74DB),
(60568,'Mac','A64','WoWC',0x4CB6793447021056A4D3A4DC0D187AA9),
(60568,'Mac','x64','WoW',0x97CE8361B5B5F0E63463C3CB028C4553),
(60568,'Mac','x64','WoWC',0x215E50B6E560D093731B8D2EA7A9125B),
(60568,'Win','A64','WoW',0x788B2E434F8F94C2F30912640E1C28E6),
(60568,'Win','x64','WoW',0x2EA108C13157170527F2CDF2581216A2),
(60568,'Win','x64','WoWC',0x2D180D7E0F83BBAE38177A02273AC016);

UPDATE `realmlist` SET `gamebuild`=60568 WHERE `gamebuild`=60490;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60568';
