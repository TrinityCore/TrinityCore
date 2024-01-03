DELETE FROM `build_info` WHERE `build`=49343;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(49343,10,0,7,NULL,NULL,'301A0B4C0942B9B6F605B903AD6C1F60',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=49343 WHERE `gamebuild` IN(49267, 48999);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '49343';
