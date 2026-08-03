DELETE FROM `build_info` WHERE `build` IN (68887);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(68887,12,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68887 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(68887,'Mac','A64','WoW',0x791AE732CD34C5860B70F8E76086C3E7),
(68887,'Mac','A64','WoWC',0x9F28EFD80C1EC42492D226371599CFB1),
(68887,'Mac','x64','WoW',0x703468E9D218D3C32196A9D770D50C26),
(68887,'Mac','x64','WoWC',0x05A417FD3AA8C71891A802B876FD923B),
(68887,'Win','A64','WoW',0x56CC340F63357AC05F5C29E197220640),
(68887,'Win','x64','WoW',0x5FEF8A5E50C913780D0EBFA21995F942),
(68887,'Win','x64','WoWC',0x8B875D86DC0DE02E6C3035C4336C411B);

UPDATE `realmlist` SET `gamebuild`=68887 WHERE `gamebuild`=68453;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68887';
