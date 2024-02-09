DELETE FROM `build_info` WHERE `build`=53040;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(53040,10,2,5,NULL,NULL,'2F1283BF7B7F307B70DBBD75CC42D7C3',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=53040 WHERE `gamebuild`=53007;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '53040';
