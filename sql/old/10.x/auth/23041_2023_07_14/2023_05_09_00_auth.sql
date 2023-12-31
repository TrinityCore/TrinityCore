DELETE FROM `build_info` WHERE `build`=49474;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49474,10,1,0,NULL,NULL,'44A7D2B352EE3D098A3CB4C2F1065E37',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49474 WHERE `gamebuild`=49444;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49474';
