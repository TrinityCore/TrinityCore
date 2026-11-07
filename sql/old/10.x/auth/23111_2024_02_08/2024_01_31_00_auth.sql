DELETE FROM `build_info` WHERE `build`=53104;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53104,10,2,5,NULL,NULL,'DBD79EC8DF044B53C78931B985CAB406',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53104 WHERE `gamebuild`=53040;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53104';
