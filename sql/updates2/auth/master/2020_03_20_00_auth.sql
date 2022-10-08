DELETE FROM `build_info` WHERE `build`=33724;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(33724,8,3,0,NULL,NULL,'38F7BBCF284939DD20E8C64CDBF9FE77',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=33724 WHERE `gamebuild`=33528;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '33724';
