DELETE FROM `build_info` WHERE `build`=40000;
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`,`winAuthSeed`,`win64AuthSeed`,`mac64AuthSeed`,`winChecksumSeed`,`macChecksumSeed`) VALUES
(40000,9,1,0,NULL,NULL,'4CB1433AB637F09F03FBBD1B221B04B0',NULL,NULL,NULL);

UPDATE `realmlist` SET `gamebuild`=40000 WHERE `gamebuild`=39804;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int(10) unsigned NOT NULL DEFAULT '40000';
