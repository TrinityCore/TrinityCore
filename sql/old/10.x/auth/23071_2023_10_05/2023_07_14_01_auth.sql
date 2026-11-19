DELETE FROM `build_info` WHERE `build`=50467;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(50467,10,1,5,NULL,NULL,'5E996B1CDCEE68432D6340138E68D1EB',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=50467 WHERE `gamebuild`=50438;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '50467';
