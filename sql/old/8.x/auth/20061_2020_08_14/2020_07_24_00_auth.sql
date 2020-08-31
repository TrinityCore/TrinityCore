DELETE FROM `build_info` WHERE `build`=35284;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(35284,8,3,7,NULL,NULL,'EA3818E7DCFD2009DBFC83EE3C1E4F1B',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=35284 WHERE `gamebuild`=35249;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '35284';
