DELETE FROM `build_info` WHERE `build` IN (63906);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63906,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63906 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63906,'Mac','A64','WoW',0x2498B74093269B1CC2A597BF368BF808),
(63906,'Mac','A64','WoWC',0x1A6B72DA01501C0B1FCE84BF42F2952D),
(63906,'Mac','x64','WoW',0x3CD6B638DED480F69E9DB88B9C8E52B9),
(63906,'Mac','x64','WoWC',0x6C931FF70F78BAD0707EA57157D40718),
(63906,'Win','A64','WoW',0x5ECAB6CD8F056268F02B3ACC984A5769),
(63906,'Win','x64','WoW',0xA58FDAC26513D567C1F128339126C602),
(63906,'Win','x64','WoWC',0xCB2C6E16508E82C2529F1C6CD2E6E6D9);

UPDATE `realmlist` SET `gamebuild`=63906 WHERE `gamebuild`=63834;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63906';
