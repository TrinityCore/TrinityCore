DELETE FROM `build_info` WHERE `build` IN (63163);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63163,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63163 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63163,'Mac','A64','WoW',0xA8DAF8783FBCEDC838F06D14F9337EB4),
(63163,'Mac','A64','WoWC',0xA447DA7F38F1082999C66C6F403CEB21),
(63163,'Mac','x64','WoW',0x396AF90D95CC4F0DF2A58C3BE3DA6C55),
(63163,'Mac','x64','WoWC',0x0D1573C127ABCC39CBB98976F87C0D49),
(63163,'Win','A64','WoW',0xD861754AF8BF0BF9AD55131DB40D4F1D),
(63163,'Win','x64','WoW',0x79261C76FC38EBE8BEC0065DE478B8DF),
(63163,'Win','x64','WoWC',0xE831CF15178929EC992A5389822B03E0);

UPDATE `realmlist` SET `gamebuild`=63163 WHERE `gamebuild`=63003;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63163';
