DELETE FROM `build_info` WHERE `build`=52106;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(52106,10,2,0,NULL,NULL,'95F43869B7D881212CBC1690B8F393ED',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=52106 WHERE `gamebuild`=52095;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '52106';
