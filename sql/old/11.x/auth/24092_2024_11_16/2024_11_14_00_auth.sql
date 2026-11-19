DELETE FROM `build_info` WHERE `build` IN (57534);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57534,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57534 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57534,'Mac','A64','WoW',0x073B823E8991A0DF012AE33D661A6060),
(57534,'Mac','A64','WoWC',0xC8824559DC24858EA7E3BD0971F98A15),
(57534,'Mac','x64','WoW',0x0C7C67AAAD4011AA9D81AB838B255CDF),
(57534,'Mac','x64','WoWC',0xCE9CD9A02B04F0C3B126F3C7E1BF7228),
(57534,'Win','A64','WoW',0xCC612F1485F158C8B2730B7DFD926563),
(57534,'Win','x64','WoW',0x948857BF76A28FD24C5A06D18B4F2FCF),
(57534,'Win','x64','WoWC',0x62B0812A4518C21360685D4422C2A312);

UPDATE `realmlist` SET `gamebuild`=57534 WHERE `gamebuild`=57388;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57534';
