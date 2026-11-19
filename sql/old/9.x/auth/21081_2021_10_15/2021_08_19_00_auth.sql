DELETE FROM `build_info` WHERE `build`=39804;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(39804,9,1,0,NULL,NULL,'E42D2BBA12ED260A76F9B1E477E19EA5',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=39804 WHERE `gamebuild`=39653;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '39804';
