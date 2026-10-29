DELETE FROM `build_info` WHERE `build` IN (70529,70575);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70529,12,1,5,NULL),
(70575,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build` IN (70529,70575) AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70529,'Mac','A64','WoW',0x0408CAFC2C070E5991D94A6345B2663B),
(70529,'Mac','A64','WoWC',0x014D125277570AE4C953276499F72A25),
(70529,'Mac','x64','WoW',0x0FFE6FD7A1307064A7A454E325D1052D),
(70529,'Mac','x64','WoWC',0x609A7440C776B25BBD3923136C1192FF),
(70529,'Win','A64','WoW',0x3CDA448E8DEED00675CF41AB47062049),
(70529,'Win','x64','WoW',0x957693BB98EFE9146B8359828E20461F),
(70529,'Win','x64','WoWC',0x047BF9EE3AC148D0FFFC1373D18A250A),
(70575,'Mac','A64','WoW',0xC87E0511A36D4CFF7347757EF213A1A7),
(70575,'Mac','A64','WoWC',0x1F2110BF0C70A172A9808D36F532E36E),
(70575,'Mac','x64','WoW',0x0979E4CCAF0F4AD5C0B200DE21E5BA9B),
(70575,'Mac','x64','WoWC',0x9C6F16741648CBAFB76549C712872A0B),
(70575,'Win','A64','WoW',0x8E3C7A9ED8943263F9378CC7E2BD842B),
(70575,'Win','x64','WoW',0x2B890C4A9196B48024367B46B930A4F0),
(70575,'Win','x64','WoWC',0x7BEF3BF3827C1090C4DA03AA49A83304);

UPDATE `realmlist` SET `gamebuild`=70575 WHERE `gamebuild` IN (70448,70529);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70575';
