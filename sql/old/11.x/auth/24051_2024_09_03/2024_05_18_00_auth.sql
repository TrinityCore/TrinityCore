DELETE FROM `build_info` WHERE `build`=54762;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(54762,10,2,7,NULL,NULL,'5F7FDA560030255445B713456A286CFA',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=54762 WHERE `gamebuild`=54736;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '54762';
