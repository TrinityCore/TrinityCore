DELETE FROM `build_info` WHERE `build` IN (62748);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62748,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62748 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62748,'Mac','A64','WoW',0x9CAC1407FB10E3FDA83DAC1853428221),
(62748,'Mac','A64','WoWC',0x871EA7435FE7EF66FB7DA5608907D071),
(62748,'Mac','x64','WoW',0x831C90A6467734EB2F25E19A08216731),
(62748,'Mac','x64','WoWC',0x0EB9A67428B9A658EC5A1FEA4A3CFAC3),
(62748,'Win','A64','WoW',0x56C59031E7D37485DAD25A2BC4A49B86),
(62748,'Win','x64','WoW',0x099FE6DC3AD0811C751C0DA819D032B4),
(62748,'Win','x64','WoWC',0x6ECA332852D9BFF77CE2A9D71A976D55);

UPDATE `realmlist` SET `gamebuild`=62748 WHERE `gamebuild`=62706;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62748';
