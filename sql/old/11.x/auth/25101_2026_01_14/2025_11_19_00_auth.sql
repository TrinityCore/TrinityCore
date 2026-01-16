DELETE FROM `build_info` WHERE `build` IN (64502);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64502,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64502 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64502,'Mac','A64','WoW',0x9F782C29580703ECF3148E3E78B3B45B),
(64502,'Mac','A64','WoWC',0x17168E59E27ECE41AAD719777413668F),
(64502,'Mac','x64','WoW',0xDA795FF3960DE8212AD6C97C4619BFD0),
(64502,'Mac','x64','WoWC',0x6DCE3BA9C0ACF638AE599680200483AE),
(64502,'Win','A64','WoW',0x51DF09ABE30D38142EB5942ED774301B),
(64502,'Win','x64','WoW',0x54D307CF2BC84E50E94C2D3A95CD6D7B),
(64502,'Win','x64','WoWC',0xA968CFA8B0558F433B3E483E844FBFC3);

UPDATE `realmlist` SET `gamebuild`=64502 WHERE `gamebuild`=64484;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64502';
