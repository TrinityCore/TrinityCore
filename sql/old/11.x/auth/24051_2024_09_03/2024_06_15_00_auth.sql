DELETE FROM `build_info` WHERE `build`=55142;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(55142,10,2,7,NULL,NULL,'298B99B5AD67EA3D2AB4B3E07A415305',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=55142 WHERE `gamebuild`=54988;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '55142';
